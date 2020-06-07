#include "../print_digimon.h"

/*
name: Growlmon
size: 16x16
*/

/*
"       ## ###   ",
"    ###### ##   ",
"   ##  #  # #   ",
" ##     ## # #  ",
" #  #  ##  ##   ",
" #####     # #  ",
" #          #   ",
"  #####     #   ",
"     #  ##  # ##",
"  ###  #     # #",
" #  # # #    # #",
" ## # ## # # # #",
" # # # ##### # #",
" ##   #   #   # ",
"# #   #### # # #",
"#######  #######",
*/
static void print_growlmon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000001, 0b10111000},
        {0b00001111, 0b11011000},
        {0b00011001, 0b00101000},
        {0b01100000, 0b11010100},
        {0b01001001, 0b10011000},
        {0b01111100, 0b00010100},
        {0b01000000, 0b00001000},
        {0b00111110, 0b00001000},
        {0b00000100, 0b11001011},
        {0b00111001, 0b00000101},
        {0b01001010, 0b10000101},
        {0b01101011, 0b01010101},
        {0b01010101, 0b11110101},
        {0b01100010, 0b00100010},
        {0b10100011, 0b11010101},
        {0b11111110, 0b01111111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"       ## ###   ",
"    ###### ##   ",
"   ##   #  # #  ",
" ##      ## # # ",
" #  #   ##  ##  ",
" #####      # # ",
" #           #  ",
"  #####      #  ",
"     #    #   ##",
"  ###    #   ## ",
" #  #   #### ## ",
" # ##   # # # # ",
" ##  #   ###  # ",
" # #  #### # # #",
" ###############",
*/
static void print_growlmon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000001, 0b10111000},
        {0b00001111, 0b11011000},
        {0b00011000, 0b10010100},
        {0b01100000, 0b01101010},
        {0b01001000, 0b11001100},
        {0b01111100, 0b00001010},
        {0b01000000, 0b00000100},
        {0b00111110, 0b00000100},
        {0b00000100, 0b00100011},
        {0b00111000, 0b01000110},
        {0b01001000, 0b11110110},
        {0b01011000, 0b10101010},
        {0b01100100, 0b01110010},
        {0b01010011, 0b11010101},
        {0b01111111, 0b11111111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_growlmon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_growlmon_neutral(matrix, x, y, mirror);
    } else {
        print_growlmon_neutral2(matrix, x, y, mirror);
    }
}