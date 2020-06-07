#include "../print_digimon.h"

/*
name: MetalGarurumon
size: 16x16
*/

/*
"    ###   ###   ",
"   #  #  #  #   ",
"  # #####  #    ",
"  ##    # #     ",
"  #   ## ##   ##",
"##   ##   #  # #",
"#  #     ### # #",
"### #####  ### #",
" #     #   #  # ",
"  ####  ###    #",
"    #  #     # #",
"    #  # #  #  #",
"   #  #  #  #  #",
"  ##  #  ##### #",
" # # # # # #   #",
" ########  #####",
*/
void print_metalgarurumon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00001110, 0b00111000},
        {0b00010010, 0b01001000},
        {0b00101111, 0b10010000},
        {0b00110000, 0b10100000},
        {0b00100011, 0b01100011},
        {0b11000110, 0b00100101},
        {0b10010000, 0b01110101},
        {0b11101111, 0b10011101},
        {0b01000001, 0b00010010},
        {0b00111100, 0b11100001},
        {0b00001001, 0b00000101},
        {0b00001001, 0b01001001},
        {0b00010010, 0b01001001},
        {0b00110010, 0b01111101},
        {0b01010101, 0b01010001},
        {0b01111111, 0b10011111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"   ###     ###  ",
"  # #######  #  ",
"  ##    #   #   ",
"  #   ## # #  ##",
"##   ##   #  # #",
"#  #     ## #  #",
"### #####  ## # ",
" #     #   #  # ",
"  ##### ###  #  ",
" #           #  ",
"# # ## #     #  ",
"# #  # ## #  ## ",
"# #  ######    #",
" ####    # #   #",
"          ##### ",
*/
static void print_metalgarurumon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00011100, 0b00011100},
        {0b00101111, 0b11100100},
        {0b00110000, 0b10001000},
        {0b00100011, 0b01010011},
        {0b11000110, 0b00100101},
        {0b10010000, 0b01101001},
        {0b11101111, 0b10011010},
        {0b01000001, 0b00010010},
        {0b00111110, 0b11100100},
        {0b01000000, 0b00000100},
        {0b10101101, 0b00000100},
        {0b10100101, 0b10100110},
        {0b10100111, 0b11100001},
        {0b01111000, 0b01010001},
        {0b00000000, 0b00111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

static void print_metalgarurumon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_metalgarurumon_neutral(matrix, x, y, mirror);
    } else {
        print_metalgarurumon_neutral2(matrix, x, y, mirror);
    }
}
