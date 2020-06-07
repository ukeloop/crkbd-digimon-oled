#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include "ssd1306.h"

struct ScreenMatrix {
    uint8_t screen[DisplayWidth][MatrixRows];
    bool dirty;
};
typedef struct ScreenMatrix ScreenMatrix;
extern struct ScreenMatrix g_screen;

uint8_t revbits8(uint8_t v);

void screen_clear(ScreenMatrix* screen);
void screen_update(ScreenMatrix *dest, const ScreenMatrix *source);

void screen_draw_bit(ScreenMatrix* screen, uint8_t x, uint8_t y);
void screen_draw_byte(ScreenMatrix* screen, uint8_t x, uint8_t y, uint8_t bits);

#endif // SCREEN_H