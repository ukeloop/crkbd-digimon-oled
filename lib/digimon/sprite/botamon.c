#include "../print_digimon.h"

/*
name: Botamon
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
"                ",
"                ",
"                ",
"      #  #      ",
"     ######     ",
"     # ## #     ",
"     ##  ##     ",
"    ########    ",
*/
static void print_botamon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000010, 0b01000000},
        {0b00000111, 0b11100000},
        {0b00000101, 0b10100000},
        {0b00000110, 0b01100000},
        {0b00001111, 0b11110000},
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
"                ",
"                ",
"                ",
"                ",
"                ",
"      #  #      ",
"     ######     ",
"     # ####     ",
"     #### #     ",
"    ########    ",
*/
static void print_botamon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000010, 0b01000000},
        {0b00000101, 0b11100000},
        {0b00000111, 0b10100000},
        {0b00001111, 0b11110000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_botamon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_botamon_neutral(matrix, x, y, mirror);
    } else {
        print_botamon_neutral2(matrix, x, y, mirror);
    }
}
