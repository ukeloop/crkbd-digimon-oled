#include "../print_digimon.h"

/*
name: WarGrowlmon
size: 16x16
*/

/*
"    ## ###  ### ",
"    #### ###  # ",
" ###      #  #  ",
" #    ##  # #   ",
" #   ##  # #####",
"  ##    # ###  #",
" #  #### ###  # ",
" ###    ###  #  ",
"  # #####  #####",
"  ##    ####   #",
"####  ####    ##",
"#   ###      ###",
" #  #  #   ### #",
" #####  ###   # ",
"# #  ##### # # #",
"#######  #######",
*/
static void print_wargrowlmon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00001101, 0b11001110},
        {0b00001111, 0b01110010},
        {0b01110000, 0b00100100},
        {0b01000011, 0b00101000},
        {0b01000110, 0b01011111},
        {0b00110000, 0b10111001},
        {0b01001111, 0b01110010},
        {0b01110000, 0b11100100},
        {0b00101111, 0b10011111},
        {0b00110000, 0b11110001},
        {0b11110011, 0b11000011},
        {0b10001110, 0b00000111},
        {0b01001001, 0b00011101},
        {0b01111100, 0b11100010},
        {0b10100111, 0b11010101},
        {0b11111110, 0b01111111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"    ## ###  ### ",
"    #### ###  # ",
" ###      #  #  ",
" #    ##  # #   ",
" #   ##  # #####",
"  ##    # ###  #",
" #  #### ###  # ",
" ###    ###  #  ",
"  # #####  #####",
"  ##   #####   #",
"## #  #       ##",
"#   ####     ###",
" #####  ######  ",
" # #  ### # # # ",
" ####### ###### ",
*/
static void print_wargrowlmon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00001101, 0b11001110},
        {0b00001111, 0b01110010},
        {0b01110000, 0b00100100},
        {0b01000011, 0b00101000},
        {0b01000110, 0b01011111},
        {0b00110000, 0b10111001},
        {0b01001111, 0b01110010},
        {0b01110000, 0b11100100},
        {0b00101111, 0b10011111},
        {0b00110001, 0b11110001},
        {0b11010010, 0b00000011},
        {0b10001111, 0b00000111},
        {0b01111100, 0b11111100},
        {0b01010011, 0b10101010},
        {0b01111111, 0b01111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_wargrowlmon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_wargrowlmon_neutral(matrix, x, y, mirror);
    } else {
        print_wargrowlmon_neutral2(matrix, x, y, mirror);
    }
}