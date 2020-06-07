#include "../screen.h"

void print_digimon(ScreenMatrix* screen, const uint8_t dots[][2], uint8_t x, uint8_t y, bool mirror) {
    uint8_t col, row;
    const uint8_t dots_w = 2;
    const uint8_t dots_h = 16;
    uint8_t dots_y = y;

    for (col = 0; col < dots_h; ++col, ++dots_y) {
        for (row = 0; row < dots_w; ++row) {
            screen_draw_byte(screen, x + row * 8, dots_y, !mirror ? dots[col][row] : revbits8(dots[col][(dots_w - row - 1)]));
        }
    }
}