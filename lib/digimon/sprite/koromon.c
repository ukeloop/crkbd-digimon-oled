#include "../print_digimon.h"

/*
name: Koromon
size: 16x16
*/

/*
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"    ##   ##     ",
"    # ### #     ",
"   #       #    ",
"  #  #   #  #   ",
"  #  #   #  #   ",
"  #    #    #   ",
"  #         #   ",
"   #########    ",
*/
static void print_koromon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00001100, 0b01100000},
        {0b00001011, 0b10100000},
        {0b00010000, 0b00010000},
        {0b00100100, 0b01001000},
        {0b00100100, 0b01001000},
        {0b00100001, 0b00001000},
        {0b00100000, 0b00001000},
        {0b00011111, 0b11110000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"    ##   ##     ",
"    # ### #     ",
"   #       #    ",
"  #  #   #  #   ",
"  #  #   #  #   ",
"  #   ###   #   ",
"  #         #   ",
"  #         #   ",
"   #       #    ",
"    #######     ",
*/
static void print_koromon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00001100, 0b01100000},
        {0b00001011, 0b10100000},
        {0b00010000, 0b00010000},
        {0b00100100, 0b01001000},
        {0b00100100, 0b01001000},
        {0b00100011, 0b10001000},
        {0b00100000, 0b00001000},
        {0b00100000, 0b00001000},
        {0b00100000, 0b00001000},
        {0b00010000, 0b00010000},
        {0b00001111, 0b11100000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_koromon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_koromon_neutral(matrix, x, y, mirror);
    } else {
        print_koromon_neutral2(matrix, x, y, mirror);
    }
}
