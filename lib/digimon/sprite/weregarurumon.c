#include "../print_digimon.h"

/*
name: WereGarurumon
size: 16x16
*/

/*
"     ##     ##  ",
"    # #### # #  ",
"    ##    #  #  ",
"    #  ###  #   ",
" ###  # #  ##   ",
" #       ####   ",
" #   #     ##   ",
"  #####   ##    ",
"  #         # ##",
"   ####      # #",
"  # #      # # #",
"  # #######  # #",
"   ##     #  ## ",
"  ## ###   ###  ",
" #    # #     # ",
" ###### ####### ",
*/
static void print_weregarurumon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000110, 0b00001100},
        {0b00001011, 0b11010100},
        {0b00001100, 0b00100100},
        {0b00001001, 0b11001000},
        {0b01110010, 0b10011000},
        {0b01000000, 0b01111000},
        {0b01000100, 0b00011000},
        {0b00111110, 0b00110000},
        {0b00100000, 0b00001011},
        {0b00011110, 0b00000101},
        {0b00101000, 0b00010101},
        {0b00101111, 0b11100101},
        {0b00011000, 0b00100110},
        {0b00110111, 0b00011100},
        {0b01000010, 0b10000010},
        {0b01111110, 0b11111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"     ##     ##  ",
"    # #### # #  ",
"    ##    #  #  ",
"    #  ###  #   ",
" ###  # #  ##   ",
" #       ####   ",
" #   #     ##   ",
"  #####   ##    ",
"  #         #   ",
"   ####      #  ",
"  # #     #  ###",
"  #  #####   # #",
"  ###     #### #",
" #    ###     # ",
" ###### ####### ",
*/
static void print_weregarurumon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000110, 0b00001100},
        {0b00001011, 0b11010100},
        {0b00001100, 0b00100100},
        {0b00001001, 0b11001000},
        {0b01110010, 0b10011000},
        {0b01000000, 0b01111000},
        {0b01000100, 0b00011000},
        {0b00111110, 0b00110000},
        {0b00100000, 0b00001000},
        {0b00011110, 0b00000100},
        {0b00101000, 0b00100111},
        {0b00100111, 0b11000101},
        {0b00111000, 0b00111101},
        {0b01000011, 0b10000010},
        {0b01111110, 0b11111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_weregarurumon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_weregarurumon_neutral(matrix, x, y, mirror);
    } else {
        print_weregarurumon_neutral2(matrix, x, y, mirror);
    }
}
