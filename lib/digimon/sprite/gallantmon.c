#include "../print_digimon.h"

/*
name: Gallantmon
size: 16x16
*/

/*
"     ## ###     ",
"    ####  #     ",
"   ###   ##     ",
"  #    ###      ",
"  #  ## # #     ",
"  ####### ###   ",
" # #    ##   #  ",
" # ##### #   #  ",
"  ##      ###   ",
" # # ## ###  #  ",
" ## #  ##  # #  ",
"#  #    #   ### ",
"# ### #  ###### ",
" ##  ## ## #####",
" # #  ### # ### ",
" ###### #####   ",
*/
static void print_gallantmon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000110, 0b11100000},
        {0b00001111, 0b00100000},
        {0b00011100, 0b01100000},
        {0b00100001, 0b11000000},
        {0b00100110, 0b10100000},
        {0b00111111, 0b10111000},
        {0b01010000, 0b11000100},
        {0b01011111, 0b01000100},
        {0b00110000, 0b00111000},
        {0b01010110, 0b11100100},
        {0b01101001, 0b10010100},
        {0b10010000, 0b10001110},
        {0b10111010, 0b01111110},
        {0b01100110, 0b11011111},
        {0b01010011, 0b10101110},
        {0b01111110, 0b11111000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"     ## ###     ",
"    ####  #     ",
"   ###   ##     ",
"  #    ####     ",
"  #  ## #  #    ",
"  ####### ###   ",
" # #    ##   #  ",
" # ##### #   #  ",
"  ##    ##### # ",
" # # ## ####   #",
" ## ## #  #### #",
" #   # #   #  ##",
"##  #####  #  ##",
"# # #### ## ####",
"#####     ###  #",
*/
static void print_gallantmon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000110, 0b11100000},
        {0b00001111, 0b00100000},
        {0b00011100, 0b01100000},
        {0b00100001, 0b11100000},
        {0b00100110, 0b10010000},
        {0b00111111, 0b10111000},
        {0b01010000, 0b11000100},
        {0b01011111, 0b01000100},
        {0b00110000, 0b11111010},
        {0b01010110, 0b11110001},
        {0b01101101, 0b00111101},
        {0b01000101, 0b00010011},
        {0b11001111, 0b10010011},
        {0b10101111, 0b01101111},
        {0b11111000, 0b00111001},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_gallantmon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_gallantmon_neutral(matrix, x, y, mirror);
    } else {
        print_gallantmon_neutral2(matrix, x, y, mirror);
    }
}