#include "../print_digimon.h"

/*
name: Guilmon
size: 16x16
*/

/*
"                ",
"     ### ###### ",
"    ######    # ",
"   #         #  ",
"  ##   ##  ##   ",
" #      ##  #   ",
" #  #  ###   #  ",
" #####      ##  ",
"  #        ##   ",
"   ###  ## #  ##",
"  # #  #    ## #",
"  ###  #### ## #",
"    #       # # ",
"  ####   #####  ",
" # # #### # # # ",
" ###### ####### ",
*/
static void print_guilmon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000111, 0b01111110},
        {0b00001111, 0b11000010},
        {0b00010000, 0b00000100},
        {0b00110001, 0b10011000},
        {0b01000000, 0b11001000},
        {0b01001001, 0b11000100},
        {0b01111100, 0b00001100},
        {0b00100000, 0b00011000},
        {0b00011100, 0b11010011},
        {0b00101001, 0b00001101},
        {0b00111001, 0b11101101},
        {0b00001000, 0b00001010},
        {0b00111100, 0b01111100},
        {0b01010111, 0b10101010},
        {0b01111110, 0b11111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"                ",
"     ### ###### ",
"    ######    # ",
"   #        ##  ",
"  ##   ##    #  ",
" #      ##    # ",
" #  #  ###   ## ",
" #####      ##  ",
"  #        ##   ",
"   ###   # #  ##",
"   ##   #   ## #",
"  # #   ### ## #",
"  ####  ##### # ",
"  # # ## # # #  ",
"  ############  ",
*/
static void print_guilmon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000111, 0b01111110},
        {0b00001111, 0b11000010},
        {0b00010000, 0b00001100},
        {0b00110001, 0b10000100},
        {0b01000000, 0b11000010},
        {0b01001001, 0b11000110},
        {0b01111100, 0b00001100},
        {0b00100000, 0b00011000},
        {0b00011100, 0b01010011},
        {0b00011000, 0b10001101},
        {0b00101000, 0b11101101},
        {0b00111100, 0b11111010},
        {0b00101011, 0b01010100},
        {0b00111111, 0b11111100},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_guilmon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_guilmon_neutral(matrix, x, y, mirror);
    } else {
        print_guilmon_neutral2(matrix, x, y, mirror);
    }
}
