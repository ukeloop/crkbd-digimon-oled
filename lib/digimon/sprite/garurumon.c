#include "../print_digimon.h"

/*
name: Garurumon
size: 16x16
*/

/*
"                ",
"   ##     ##    ",
"  # #### # #    ",
"  ##    #  # ## ",
"  #       # #  #",
"##   ###  #  # #",
"#  # ##  ##  # #",
"#####   ### ## #",
" #        ##  # ",
"  ####   ###   #",
"    #      # ###",
"    # ##    # ##",
"    # #  #  #  #",
"   ## #  ##### #",
"  #  #   # #   #",
"  #######  #####",
*/
static void print_garurumon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00011000, 0b00110000},
        {0b00101111, 0b01010000},
        {0b00110000, 0b10010110},
        {0b00100000, 0b00101001},
        {0b11000111, 0b00100101},
        {0b10010110, 0b01100101},
        {0b11111000, 0b11101101},
        {0b01000000, 0b00110010},
        {0b00111100, 0b01110001},
        {0b00001000, 0b00010111},
        {0b00001011, 0b00001011},
        {0b00001010, 0b01001001},
        {0b00011010, 0b01111101},
        {0b00100100, 0b01010001},
        {0b00111111, 0b10011111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"   ##     ##    ",
"  # #### # #    ",
"  ##    #  #    ",
"  #       ##  # ",
"##    ##  #  # #",
"#  # ##  ## #  #",
"#####   ##### # ",
" #        ## ## ",
"  ####   ##  #  ",
" #           #  ",
"# # ## #    ##  ",
"# #  # ## #  ## ",
"# #  ######    #",
" ####    # #   #",
"          ##### ",
*/
static void print_garurumon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00011000, 0b00110000},
        {0b00101111, 0b01010000},
        {0b00110000, 0b10010000},
        {0b00100000, 0b00110010},
        {0b11000011, 0b00100101},
        {0b10010110, 0b01101001},
        {0b11111000, 0b11111010},
        {0b01000000, 0b00110110},
        {0b00111100, 0b01100100},
        {0b01000000, 0b00000100},
        {0b10101101, 0b00001100},
        {0b10100101, 0b10100110},
        {0b10100111, 0b11100001},
        {0b01111000, 0b01010001},
        {0b00000000, 0b00111110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_garurumon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_garurumon_neutral(matrix, x, y, mirror);
    } else {
        print_garurumon_neutral2(matrix, x, y, mirror);
    }
}
