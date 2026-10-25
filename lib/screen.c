#include "screen.h"

#include <string.h>

struct ScreenMatrix g_screen;

void screen_clear(ScreenMatrix* screen) {
    // Clear in place instead of allocating a second 512-byte framebuffer on
    // the AVR stack. Mark the display dirty only when pixels actually change.
    bool changed = false;
    const uint8_t* pixels = (const uint8_t*)screen->screen;
    for (size_t i = 0; i < sizeof(screen->screen); ++i) {
        if (pixels[i] != 0) {
            changed = true;
            break;
        }
    }

    if (changed) {
        memset(screen->screen, 0, sizeof(screen->screen));
        screen->dirty = true;
    }
}

void screen_update(ScreenMatrix* dest, const ScreenMatrix* source) {
    if (memcmp(dest->screen, source->screen, sizeof(dest->screen)) != 0) {
        memcpy(dest->screen, source->screen, sizeof(dest->screen));
        dest->dirty = true;
    }
}

void screen_draw_bit(ScreenMatrix* screen, uint8_t x, uint8_t y) {
    if (y >= DisplayWidth || x >= DisplayHeight) {
        return;
    }

    const uint8_t page = x >> 3;
    const uint8_t bit  = x & 7;
    const uint8_t mask = (uint8_t)(1U << (7 - bit));
    uint8_t* pixel_byte = &screen->screen[y][page];

    if ((*pixel_byte & mask) == 0) {
        *pixel_byte |= mask;
        screen->dirty = true;
    }
}

void screen_draw_byte(ScreenMatrix* screen, uint8_t x, uint8_t y, uint8_t bits) {
    if (y >= DisplayWidth || x >= DisplayHeight) {
        return;
    }

    const uint8_t page  = x >> 3;
    const uint8_t shift = x & 7;
    uint8_t* first = &screen->screen[y][page];
    const uint8_t first_bits = (uint8_t)(bits >> shift);

    if ((*first | first_bits) != *first) {
        *first |= first_bits;
        screen->dirty = true;
    }

    // A byte aligned to a page boundary needs no second write. At the bottom
    // display edge page+1 would be out of bounds, so guard that access too.
    if (shift != 0 && page + 1 < MatrixRows) {
        uint8_t* second = &screen->screen[y][page + 1];
        const uint8_t second_bits = (uint8_t)(bits << (8 - shift));
        if ((*second | second_bits) != *second) {
            *second |= second_bits;
            screen->dirty = true;
        }
    }
}