#include <string.h>
#include "crkbd.h"
#include "digimon.h"

#if IS_MASTER
#    include "digimon_master.c"
#else
#    include "digimon_slave.c"
#endif

static uint16_t digimon_last_flush = 0;
static uint16_t digimon_frame      = 0;
static uint8_t  digimon_x          = DIGIMON_MAX_X / 2;
static int8_t   digimon_moment     = -1;

FUNCPTR digimon_print_function;

char digimon_name[24] = {};

void set_digimon(void) {
    if (digimon_frame % FPS != 0) {
        return;
    }

#if IS_MASTER
    set_digimon_master(&digimon_frame);
#else
    set_digimon_slave(&digimon_frame);
#endif
}

void draw_digimon_handler(struct ScreenMatrix *matrix) {
    if (is_timeout) {
        digimon_last_flush = 0;
        return;
    }

    if (digimon_last_flush == 0) {
        digimon_last_flush = timer_read();
    } else if (timer_elapsed(digimon_last_flush) > REFRESH_INTARVAL) {
        digimon_frame++;
        digimon_last_flush = timer_read();
    }

    if (digimon_frame == MAX_AGE) {
        digimon_frame = 0;
    }

    if (digimon_frame % 30 == 0) {
        if (rand() % 8 == 0) {
            digimon_moment = -digimon_moment;
        }

        if (digimon_x == DIGIMON_MAX_X) {
            digimon_moment = -1;
        } else if (digimon_x == DIGIMON_MIN_X) {
            digimon_moment = 1;
        }

        digimon_x += digimon_moment << 1;
    }

    set_digimon();

    (digimon_print_function)(matrix, (digimon_x >> 1) % 2, digimon_x, DIGIMON_Y, digimon_moment > 0);

    print_chara_p(matrix, digimon_name, 3);
}