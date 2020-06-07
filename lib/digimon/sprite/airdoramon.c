#include "../print_digimon.h"

/*
name: Airdoramon
size: 16x16
*/

/*
"        ### ##  ",
"     ###  # # # ",
"    #    #  # # ",
"   # ###  ##   #",
" ## # #    #   #",
"#         #    #",
"####           #",
" #     #   # # #",
"  #####     ## #",
"     # #   # # #",
"    # #   #   # ",
"    ##    #  # #",
"    # #    ### #",
"     # # #     #",
"      # # # # # ",
"       #######  ",
*/
static void print_airdoramon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b11101100},
        {0b00000111, 0b00101010},
        {0b00001000, 0b01001010},
        {0b00010111, 0b00110001},
        {0b01101010, 0b00010001},
        {0b10000000, 0b00100001},
        {0b11110000, 0b00000001},
        {0b01000001, 0b00010101},
        {0b00111110, 0b00001101},
        {0b00000101, 0b00010101},
        {0b00001010, 0b00100010},
        {0b00001100, 0b00100101},
        {0b00001010, 0b0011101},
        {0b00000101, 0b01000001},
        {0b00000010, 0b10101010},
        {0b00000001, 0b11111100},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"        ### ##  ",
"     ###  # # # ",
"    #    #  # # ",
"   # ###  ##   #",
" ## # #    #   #",
"#         #    #",
"####           #",
" #     #   # # #",
"  #####     ## #",
"     # #   # # #",
"    # #   #  ## ",
"    ##     ##  #",
"    # # #     # ",
"     # # # # #  ",
"      #######   ",
*/
static void print_airdoramon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b11101100},
        {0b00000111, 0b00101010},
        {0b00001000, 0b01001010},
        {0b00010111, 0b00110001},
        {0b01101010, 0b00010001},
        {0b10000000, 0b00100001},
        {0b11110000, 0b00000001},
        {0b01000001, 0b00010101},
        {0b00111110, 0b00001101},
        {0b00000101, 0b00010101},
        {0b00001010, 0b00100110},
        {0b00001100, 0b00011001},
        {0b00001010, 0b10000010},
        {0b00000101, 0b01010100},
        {0b00000011, 0b11111000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_airdoramon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_airdoramon_neutral(matrix, x, y, mirror);
    } else {
        print_airdoramon_neutral2(matrix, x, y, mirror);
    }
}
