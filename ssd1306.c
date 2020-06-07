
#ifdef SSD1306OLED

#    include "ssd1306.h"
#    include "./lib/screen.h"
#    include "i2c.h"
#    include <string.h>
#    include "print.h"
#    ifdef ADAFRUIT_BLE_ENABLE
#        include "adafruit_ble.h"
#    endif
#    ifdef PROTOCOL_LUFA
#        include "lufa.h"
#    endif
#    include "sendchar.h"
#    include "timer.h"

// Set this to 1 to help diagnose early startup problems
// when testing power-on with ble.  Turn it off otherwise,
// as the latency of printing most of the debug info messes
// with the matrix scan, causing keys to drop.
#    define DEBUG_TO_SCREEN 0

// static uint16_t last_battery_update;
// static uint32_t vbat;
//#define BatteryUpdateInterval 10000 /* milliseconds */

// 'last_flush' is declared as uint16_t,
// so this must be less than 65535
#    ifndef ScreenOffInterval
#        define ScreenOffInterval 60000 /* milliseconds */
#    endif

#    if DEBUG_TO_SCREEN
static uint8_t displaying;
#    endif

static uint16_t last_keypress = 0;
bool            is_timeout    = false;

static bool force_dirty = true;

// Write command sequence.
// Returns true on success.
static inline bool _send_cmd(uint8_t cmd) {
    bool res = false;

    if (i2c_start_write(SSD1306_ADDRESS)) {
        xprintf("failed to start write to %d\n", SSD1306_ADDRESS);
        goto done;
    }

    if (i2c_master_write(0x0 /* command byte follows */)) {
        print("failed to write control byte\n");
        goto done;
    }

    if (i2c_master_write(cmd)) {
        xprintf("failed to write command %d\n", cmd);
        goto done;
    }

    res = true;

done:
    i2c_master_stop();
    return res;
}

#    define send_cmd(c)      \
        if (!_send_cmd(c)) { \
            goto done;       \
        }
#    define send_cmds(c)                 \
        if (!_send_cmds(c, sizeof(c))) { \
            goto done;                   \
        }
#    define cmd1(X) X
#    define cmd2(X, Y) X, Y
#    define cmd3(X, Y, Z) X, Y, Z

static bool _send_cmds(const uint8_t* p, uint8_t sz) {
    for (uint8_t i = sz; i; i--) {
        send_cmd(pgm_read_byte(p++));
    }
    return true;
done:
    return false;
}

#    define SEND_CMDS(...)                                           \
        {                                                            \
            static const uint8_t _cmds[] PROGMEM = {__VA_ARGS__, 0}; \
            send_cmds(_cmds);                                        \
        }

bool iota_gfx_init(void) {
    bool success = false;

    i2c_master_init();

    SEND_CMDS(cmd1(DisplayOff), cmd2(SetDisplayClockDiv, 0x80), cmd2(SetMultiPlex, DisplayHeight - 1), cmd2(SetDisplayOffset, 0), cmd1(SetStartLine | 0x0), cmd2(SetChargePump, 0x14 /* Enable */), cmd2(SetMemoryMode, 0 /* horizontal addressing */));

    // Flips the display orientation 0 degrees
    SEND_CMDS(cmd1(SegRemap | 0x1), cmd1(ComScanDec));

    SEND_CMDS(
#    ifdef SSD1306_128X64
        cmd2(SetComPins, 0x12),
#    else
        cmd2(SetComPins, 0x2),
#    endif
        cmd2(SetContrast, 0x8f), cmd2(SetPreCharge, 0xf1), cmd2(SetVComDetect, 0x40), cmd1(DisplayAllOnResume), cmd1(NormalDisplay), cmd1(DeActivateScroll), cmd1(DisplayOn),

        cmd2(SetContrast, 0)  // Dim
    );

    success = true;

    iota_gfx_flush();

#    if DEBUG_TO_SCREEN
    print_set_sendchar(capture_sendchar);
#    endif

done:
    return success;
}

bool iota_gfx_off(void) { return _send_cmd(DisplayOff); }

bool iota_gfx_on(void) { return _send_cmd(DisplayOn); }

void iota_gfx_clear_screen(void) {}

// ビット反転
uint8_t revbits8(uint8_t v) {
    v = ((v >> 1) & 0x55) | ((v & 0x55) << 1);
    v = ((v >> 2) & 0x33) | ((v & 0x33) << 2);
    v = ((v >> 4) & 0x0F) | ((v & 0x0F) << 4);
    return v;
}

void screen_render(ScreenMatrix* screen) {
    // last_flush = timer_read();
    iota_gfx_on();
#    if DEBUG_TO_SCREEN
    ++displaying;
#    endif

    // Move to the home position
    SEND_CMDS(cmd3(PageAddr, 0, (DisplayHeight >> 3) - 1), cmd3(ColumnAddr, 0, DisplayWidth - 1));

    if (i2c_start_write(SSD1306_ADDRESS) || i2c_master_write(0x40)) {
        // Data mode
        goto done;
    }

    for (uint8_t row = 0; row < MatrixRows; ++row) {
        for (uint8_t col = 0; col < DisplayWidth; ++col) {
            uint8_t bits = screen->screen[DisplayWidth - col - 1][row];
            i2c_master_write(revbits8(bits));
        }
    }

    screen->dirty = false;

done:
    i2c_master_stop();
#    if DEBUG_TO_SCREEN
    --displaying;
#    endif
}

void iota_gfx_flush(void) { screen_render(&g_screen); }

__attribute__((weak)) void iota_gfx_task_user(void) {}

void iota_gfx_task(void) {
    iota_gfx_task_user();

    if (force_dirty) {
        iota_gfx_flush();
        force_dirty   = false;
        is_timeout    = false;
        last_keypress = timer_read();
#    if ScreenOffInterval > 0
    } else if (is_timeout || timer_elapsed(last_keypress) > ScreenOffInterval) {
        iota_gfx_off();
        is_timeout = true;
#    endif
    } else if (g_screen.dirty) {
        iota_gfx_flush();
        is_timeout = false;
    }
}

bool process_record_gfx(uint16_t keycode, keyrecord_t* record) {
    force_dirty = true;
    return true;
}

#endif