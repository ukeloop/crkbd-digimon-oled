#include "screen.h"

#include <string.h>

struct ScreenMatrix g_screen;


void screen_clear(ScreenMatrix* screen) {
    memset(screen->screen, 0, sizeof(screen->screen));
    //screen->dirty = true;
}

void screen_update(ScreenMatrix* dest, const ScreenMatrix* source) {
    if (memcmp(dest->screen, source->screen, sizeof(dest->screen))) {
        memcpy(dest->screen, source->screen, sizeof(dest->screen));
        dest->dirty = true;
    }
}

void screen_draw_bit(ScreenMatrix* screen, uint8_t x, uint8_t y) {
    const uint8_t row = x >> 3;
    const uint8_t bit = x & 7;

    screen->screen[y][row] |= 1 << (7 - bit);

    //screen->dirty = true;
}

void screen_draw_byte(ScreenMatrix* screen, uint8_t x, uint8_t y, uint8_t bits) {
    const uint8_t row   = x >> 3;
    const uint8_t shift = x & 7;

    screen->screen[y][row] |= bits >> shift;
    screen->screen[y][row + 1] |= bits << (8 - shift);

    //screen->dirty = true;
}