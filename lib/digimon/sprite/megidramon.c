#include "../print_digimon.h"

/*
name: Megidramon
size: 16x16
*/

/*
"      ###### #  ",
"    ##     ## # ",
"####  ## ## #  #",
"#    ##  #  #  #",
"# # #   ####   #",
" # # #   # #   #",
" #      #  # # #",
"  ######   ## ##",
"  # #  ## # #  #",
" ## #  # #   # #",
"#  #  # #   ### ",
"## #   ##  #   #",
"# ##   # ###   #",
"## #   ### #   #",
"  ###    ##   # ",
"     #########  ",
*/
void print_megidramon_neutral(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000011, 0b11110100},
        {0b00001100, 0b00011010},
        {0b11110011, 0b01101001},
        {0b10000110, 0b01001001},
        {0b10101000, 0b11110001},
        {0b01010100, 0b01010001},
        {0b01000000, 0b10010101},
        {0b00111111, 0b00011011},
        {0b00101001, 0b10101001},
        {0b01101001, 0b01000101},
        {0b10010010, 0b10001110},
        {0b11010001, 0b10010001},
        {0b10110001, 0b01110001},
        {0b11010001, 0b11010001},
        {0b00111000, 0b01100010},
        {0b00000111, 0b11111100},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

/*
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
*/
static void print_megidramon_neutral2(struct ScreenMatrix *matrix, uint8_t x, uint8_t y, bool mirror) {
    const uint8_t sprite[16][2] = {
        {0b00000011, 0b11110100},
        {0b00001100, 0b00011010},
        {0b11110011, 0b01101001},
        {0b10000110, 0b01001001},
        {0b10101000, 0b11110001},
        {0b01010100, 0b01010001},
        {0b01000000, 0b10010101},
        {0b00111111, 0b00011011},
        {0b00101001, 0b10101001},
        {0b01101001, 0b01000101},
        {0b10010010, 0b10001110},
        {0b11010001, 0b10010001},
        {0b10110001, 0b01110001},
        {0b11010001, 0b11010001},
        {0b00111000, 0b01100010},
        {0b00000111, 0b11111100},
    };

    print_digimon(matrix, sprite, x, y, mirror);
}

static void print_megidramon(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror) {
    if(sprite_id == 1) {
        print_megidramon_neutral(matrix, x, y, mirror);
    } else {
        print_megidramon_neutral2(matrix, x, y, mirror);
    }
}
