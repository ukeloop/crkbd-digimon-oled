#include "../print_digimon.h"

/*
name: Megadramon
size: 16x16
*/

/*
"    ######## #  ",
"  #######  # ## ",
" ###### ###  ## ",
"######  ##  ####",
"######### ######",
" #   ###   #####",
"  #     ########",
"   #####   ## ##",
"  # #     # #  #",
" ## #  ###   # #",
"#  ######   ### ",
"#  #   ##  #####",
" ###############",
"   #  # ###### #",
"    ##  #  # ## ",
"     #########  ",
*/
static void print_megadramon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00001111, 0b11110100},
        {0b00111111, 0b10010110},
        {0b01111110, 0b11100110},
        {0b11111100, 0b11001111},
        {0b11111111, 0b10111111},
        {0b01000111, 0b00011111},
        {0b00100000, 0b11111111},
        {0b00011111, 0b00011011},
        {0b00101000, 0b00101001},
        {0b01101001, 0b11000101},
        {0b10011111, 0b10001110},
        {0b10010001, 0b10011111},
        {0b01111111, 0b11111111},
        {0b00010010, 0b11111101},
        {0b00001100, 0b10010110},
        {0b00000111, 0b11111100},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"    ######## #  ",
"  #######  # ## ",
" ###### ###  ## ",
"######  ##  ####",
"######### ######",
" #   ###   #####",
"  #     ########",
"   #####   ## ##",
" ## #   ### #  #",
"#   #  #    #  #",
"#  #####   #### ",
" ###   #########",
"   #############",
"   #   #  #  # #",
"    ########### ",
*/
static void print_megadramon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00001111, 0b11110100},
        {0b00111111, 0b10010110},
        {0b01111110, 0b11100110},
        {0b11111100, 0b11001111},
        {0b11111111, 0b10111111},
        {0b01000111, 0b00011111},
        {0b00100000, 0b11111111},
        {0b00011111, 0b00011011},
        {0b01101000, 0b11101001},
        {0b10001001, 0b00001001},
        {0b10011111, 0b00011110},
        {0b01110001, 0b11111111},
        {0b00011111, 0b11111111},
        {0b00010001, 0b00100101},
        {0b00001111, 0b11111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_megadramon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_megadramon_neutral(matrix, x, y, mirror);
    } else {
        print_megadramon_neutral2(matrix, x, y, mirror);
    }
}
