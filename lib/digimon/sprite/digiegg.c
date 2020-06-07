#include "../print_digimon.h"

/*
name: Digi-Egg
size: 16x16
*/

/*
"                ",
"                ",
"                ",
"                ",
"      ####      ",
"     #    #     ",
"    ###    #    ",
"   #  ##    #   ",
"   #       ##   ",
"  #      #####  ",
"  #    ####  #  ",
"  ###        #  ",
"  ####       #  ",
"   #    ### #   ",
"    #     ##    ",
"     ######     ",
*/
static void print_digiegg_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000011, 0b11000000},
        {0b00000100, 0b00100000},
        {0b00001110, 0b00010000},
        {0b00010011, 0b00001000},
        {0b00010000, 0b00011000},
        {0b00100000, 0b01111100},
        {0b00100001, 0b11100100},
        {0b00111000, 0b00000100},
        {0b00111100, 0b00000100},
        {0b00010000, 0b11101000},
        {0b00001000, 0b00110000},
        {0b00000111, 0b11100000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
" ##          #  ",
"# #  #    #     ",
"##   ###### ##  ",
"    ## ## ### # ",
"    ######## ## ",
" ## ########    ",
" #  ###  ###   #",
"    ###  ### # #",
"  # ###  #####  ",
"  ### ### #  #  ",
"  # #  ### # #  ",
"  #   # #    #  ",
"   #  #     #   ",
"    #      #    ",
"     ######     ",
*/
static void print_digiegg_birth2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b01100000, 0b00000100},
        {0b10100100, 0b00100000},
        {0b11000111, 0b11101100},
        {0b00001101, 0b10111010},
        {0b00001111, 0b11110110},
        {0b01101111, 0b11110000},
        {0b01001110, 0b01110001},
        {0b00001110, 0b01110101},
        {0b00101110, 0b01111100},
        {0b00111011, 0b10100100},
        {0b00101001, 0b11010100},
        {0b00100010, 0b10000100},
        {0b00010010, 0b00001000},
        {0b00001000, 0b00010000},
        {0b00000111, 0b11100000},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_digiegg(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    print_digiegg_neutral(matrix, 8, y, 0);
}

void print_digiegg_birth(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    print_digiegg_birth2(matrix, 8, y, 0);
}