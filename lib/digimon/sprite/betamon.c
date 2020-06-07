#include "../print_digimon.h"

/*
name: Betamon
size: 16x16
*/

/*
"                ",
"                ",
"                ",
"                ",
"   #####        ",
"   #    ##      ",
"    #     #     ",
"    # #### #    ",
"   # #    ###   ",
"  #      ##  ###",
" # #  # #   ## #",
" # #  #    #  ##",
" #            # ",
" #     #  # #  #",
"# #####  ###   #",
"####  #### #### ",
*/
static void print_betamon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00011111, 0b00000000},
        {0b00010000, 0b11000000},
        {0b00001000, 0b00100000},
        {0b00001011, 0b11010000},
        {0b00010100, 0b00111000},
        {0b00100000, 0b01100111},
        {0b01010010, 0b10001101},
        {0b01010010, 0b00010011},
        {0b01000000, 0b00000010},
        {0b01000001, 0b00101001},
        {0b10111110, 0b01110001},
        {0b11110011, 0b11011110},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"                ",
"                ",
"                ",
"                ",
"   #####        ",
"   #    ##      ",
"    #     #     ",
"    # #### #    ",
"   # #    ###   ",
"  #      ##  ###",
" # #  # #   ## #",
" # #  #    #  ##",
" #            # ",
"##    #   ##   #",
"################",
*/
static void print_betamon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00000000, 0b00000000},
        {0b00011111, 0b00000000},
        {0b00010000, 0b11000000},
        {0b00001000, 0b00100000},
        {0b00001011, 0b11010000},
        {0b00010100, 0b00111000},
        {0b00100000, 0b01100111},
        {0b01010010, 0b10001101},
        {0b01010010, 0b00010011},
        {0b01000000, 0b00000010},
        {0b11000010, 0b00110001},
        {0b11111111, 0b11111111},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

void print_betamon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_betamon_neutral(matrix, x, y, mirror);
    } else {
        print_betamon_neutral2(matrix, x, y, mirror);
    }
}
