#include "../screen.h"
#include <stdio.h>
#include "crkbd.h"
#include "keyloger.h"

#define CHARA_WIDTH 6
#define CHARA_HEIGHT 8

void print_chara(struct ScreenMatrix *matrix, char str, uint8_t x, uint8_t y) {
    uint8_t dots[8] = {0};

    switch (str) {
        case 'a':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01100000;
            dots[3] = 0b00010000;
            dots[4] = 0b01110000;
            dots[5] = 0b10010000;
            dots[6] = 0b01111000;
            dots[7] = 0b00000000;
            break;
        case 'b':
            dots[0] = 0b10000000;
            dots[1] = 0b10000000;
            dots[2] = 0b10110000;
            dots[3] = 0b11001000;
            dots[4] = 0b10001000;
            dots[5] = 0b11001000;
            dots[6] = 0b10110000;
            dots[7] = 0b00000000;
            break;
        case 'c':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01110000;
            dots[3] = 0b10001000;
            dots[4] = 0b10000000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'd':
            dots[0] = 0b00001000;
            dots[1] = 0b00001000;
            dots[2] = 0b01101000;
            dots[3] = 0b10011000;
            dots[4] = 0b10001000;
            dots[5] = 0b10011000;
            dots[6] = 0b01101000;
            dots[7] = 0b00000000;
            break;
        case 'e':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01110000;
            dots[3] = 0b10001000;
            dots[4] = 0b11111000;
            dots[5] = 0b10000000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'f':
            dots[0] = 0b00100000;
            dots[1] = 0b01010000;
            dots[2] = 0b01000000;
            dots[3] = 0b11100000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b01000000;
            dots[7] = 0b00000000;
            break;
        case 'g':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01110000;
            dots[3] = 0b10011000;
            dots[4] = 0b10011000;
            dots[5] = 0b01101000;
            dots[6] = 0b10001000;
            dots[7] = 0b01110000;
            break;
        case 'h':
            dots[0] = 0b10000000;
            dots[1] = 0b10000000;
            dots[2] = 0b10110000;
            dots[3] = 0b11001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'i':
            dots[0] = 0b01000000;
            dots[1] = 0b00000000;
            dots[2] = 0b11000000;
            dots[3] = 0b01000000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b11100000;
            dots[7] = 0b00000000;
            break;
        case 'j':
            dots[0] = 0b00010000;
            dots[1] = 0b00000000;
            dots[2] = 0b00010000;
            dots[3] = 0b00010000;
            dots[4] = 0b00010000;
            dots[5] = 0b10010000;
            dots[6] = 0b01100000;
            dots[7] = 0b00000000;
            break;
        case 'k':
            dots[0] = 0b10000000;
            dots[1] = 0b10000000;
            dots[2] = 0b10010000;
            dots[3] = 0b10100000;
            dots[4] = 0b11000000;
            dots[5] = 0b10100000;
            dots[6] = 0b10010000;
            dots[7] = 0b00000000;
            break;
        case 'l':
            dots[0] = 0b11000000;
            dots[1] = 0b01000000;
            dots[2] = 0b01000000;
            dots[3] = 0b01000000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b11100000;
            dots[7] = 0b00000000;
            break;
        case 'm':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b11010000;
            dots[3] = 0b10101000;
            dots[4] = 0b10101000;
            dots[5] = 0b10101000;
            dots[6] = 0b10101000;
            dots[7] = 0b00000000;
            break;
        case 'n':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10110000;
            dots[3] = 0b11001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'o':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01110000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'p':
            dots[0] = 0b00000000;
            dots[1] = 0b10110000;
            dots[2] = 0b11001000;
            dots[3] = 0b11001000;
            dots[4] = 0b10110000;
            dots[5] = 0b10000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case 'q':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01101000;
            dots[3] = 0b10011000;
            dots[4] = 0b10011000;
            dots[5] = 0b01101000;
            dots[6] = 0b00001000;
            dots[7] = 0b00000000;
            break;
        case 'r':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10110000;
            dots[3] = 0b11001000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case 's':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01111100;
            dots[3] = 0b10000000;
            dots[4] = 0b00111000;
            dots[5] = 0b00000100;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case 't':
            dots[0] = 0b00100000;
            dots[1] = 0b00100000;
            dots[2] = 0b11111000;
            dots[3] = 0b00100000;
            dots[4] = 0b00100000;
            dots[5] = 0b00101000;
            dots[6] = 0b00010000;
            dots[7] = 0b00000000;
            break;
        case 'u':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10011000;
            dots[6] = 0b01101000;
            dots[7] = 0b00000000;
            break;
        case 'v':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b01010000;
            dots[6] = 0b00100000;
            dots[7] = 0b00000000;
            break;
        case 'w':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10101000;
            dots[5] = 0b10101000;
            dots[6] = 0b01010000;
            dots[7] = 0b00000000;
            break;
        case 'x':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b10001000;
            dots[3] = 0b01010000;
            dots[4] = 0b00100000;
            dots[5] = 0b01010000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'y':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01001000;
            dots[3] = 0b01001000;
            dots[4] = 0b01111000;
            dots[5] = 0b00001000;
            dots[6] = 0b10001000;
            dots[7] = 0b01110000;
            break;
        case 'z':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b11111000;
            dots[3] = 0b00010000;
            dots[4] = 0b00100000;
            dots[5] = 0b01000000;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case 'A':
            dots[0] = 0b00100000;
            dots[1] = 0b0101000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b11111000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'B':
            dots[0] = 0b11110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b11110000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b11110000;
            dots[7] = 0b00000000;
            break;
        case 'C':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10000000;
            dots[3] = 0b10000000;
            dots[4] = 0b10000000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'D':
            dots[0] = 0b11110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b11110000;
            dots[7] = 0b00000000;
            break;
        case 'E':
            dots[0] = 0b11111000;
            dots[1] = 0b10000000;
            dots[2] = 0b10000000;
            dots[3] = 0b11110000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case 'F':
            dots[0] = 0b11111000;
            dots[1] = 0b10000000;
            dots[2] = 0b10000000;
            dots[3] = 0b11110000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case 'G':
            dots[0] = 0b01111000;
            dots[1] = 0b10001000;
            dots[2] = 0b10000000;
            dots[3] = 0b10000000;
            dots[4] = 0b10011000;
            dots[5] = 0b10001000;
            dots[6] = 0b01111000;
            dots[7] = 0b00000000;
            break;
        case 'H':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b11111000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'I':
            dots[0] = 0b11100000;
            dots[1] = 0b01000000;
            dots[2] = 0b01000000;
            dots[3] = 0b01000000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b11100000;
            dots[7] = 0b00000000;
            break;
        case 'J':
            dots[0] = 0b00111000;
            dots[1] = 0b00010000;
            dots[2] = 0b00010000;
            dots[3] = 0b00010000;
            dots[4] = 0b00010000;
            dots[5] = 0b10010000;
            dots[6] = 0b01100000;
            dots[7] = 0b00000000;
            break;
        case 'K':
            dots[0] = 0b10001000;
            dots[1] = 0b10010000;
            dots[2] = 0b10100000;
            dots[3] = 0b11000000;
            dots[4] = 0b10100000;
            dots[5] = 0b10010000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'L':
            dots[0] = 0b10000000;
            dots[1] = 0b10000000;
            dots[2] = 0b10000000;
            dots[3] = 0b10000000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case 'M':
            dots[0] = 0b10001000;
            dots[1] = 0b11011000;
            dots[2] = 0b10101000;
            dots[3] = 0b10101000;
            dots[4] = 0b10101000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'N':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b11001000;
            dots[3] = 0b10101000;
            dots[4] = 0b10011000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'O':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'P':
            dots[0] = 0b11110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b11110000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case 'Q':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10101000;
            dots[5] = 0b10010000;
            dots[6] = 0b01101000;
            dots[7] = 0b00000000;
            break;
        case 'R':
            dots[0] = 0b11110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b11110000;
            dots[4] = 0b10100000;
            dots[5] = 0b10010000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'S':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10000000;
            dots[3] = 0b01110000;
            dots[4] = 0b00001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'T':
            dots[0] = 0b11111000;
            dots[1] = 0b10101000;
            dots[2] = 0b00100000;
            dots[3] = 0b00100000;
            dots[4] = 0b00100000;
            dots[5] = 0b00100000;
            dots[6] = 0b00100000;
            dots[7] = 0b00000000;
            break;
        case 'U':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case 'V':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10001000;
            dots[4] = 0b10001000;
            dots[5] = 0b01010000;
            dots[6] = 0b00100000;
            dots[7] = 0b00000000;
            break;
        case 'W':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b10101000;
            dots[4] = 0b10101000;
            dots[5] = 0b10101000;
            dots[6] = 0b01010000;
            dots[7] = 0b00000000;
            break;
        case 'X':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b01010000;
            dots[3] = 0b00100000;
            dots[4] = 0b01010000;
            dots[5] = 0b10001000;
            dots[6] = 0b10001000;
            dots[7] = 0b00000000;
            break;
        case 'Y':
            dots[0] = 0b10001000;
            dots[1] = 0b10001000;
            dots[2] = 0b01010000;
            dots[3] = 0b00100000;
            dots[4] = 0b00100000;
            dots[5] = 0b00100000;
            dots[6] = 0b00100000;
            dots[7] = 0b00000000;
            break;
        case 'Z':
            dots[0] = 0b11111000;
            dots[1] = 0b00001000;
            dots[2] = 0b00010000;
            dots[3] = 0b01110000;
            dots[4] = 0b01000000;
            dots[5] = 0b10000000;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case ':':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01000000;
            dots[3] = 0b00000000;
            dots[4] = 0b01000000;
            dots[5] = 0b00000000;
            dots[6] = 0b00000000;
            dots[7] = 0b00000000;
            break;
        case ';':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b01000000;
            dots[3] = 0b00000000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case '\'':
            dots[0] = 0b01100000;
            dots[1] = 0b01100000;
            dots[2] = 0b01000000;
            dots[3] = 0b10000000;
            dots[4] = 0b00000000;
            dots[5] = 0b00000000;
            dots[6] = 0b00000000;
            dots[7] = 0b00000000;
            break;
        case '+':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b00100000;
            dots[3] = 0b00100000;
            dots[4] = 0b11111000;
            dots[5] = 0b00100000;
            dots[6] = 0b00100000;
            dots[7] = 0b00000000;
            break;
        case ',':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b00000000;
            dots[3] = 0b00000000;
            dots[4] = 0b01100000;
            dots[5] = 0b01100000;
            dots[6] = 0b01000000;
            dots[7] = 0b10000000;
            break;
        case '-':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b00000000;
            dots[3] = 0b00000000;
            dots[4] = 0b11111000;
            dots[5] = 0b00000000;
            dots[6] = 0b00000000;
            dots[7] = 0b00000000;
            break;
        case '.':
            dots[0] = 0b00000000;
            dots[1] = 0b00000000;
            dots[2] = 0b00000000;
            dots[3] = 0b00000000;
            dots[4] = 0b00000000;
            dots[5] = 0b00110000;
            dots[6] = 0b00110000;
            dots[7] = 0b00000000;
            break;
        case '/':
            dots[0] = 0b00000000;
            dots[1] = 0b00000100;
            dots[2] = 0b00001000;
            dots[3] = 0b00010000;
            dots[4] = 0b00100000;
            dots[5] = 0b01000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case '0':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10011000;
            dots[3] = 0b10101000;
            dots[4] = 0b11001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case '1':
            dots[0] = 0b01000000;
            dots[1] = 0b11000000;
            dots[2] = 0b01000000;
            dots[3] = 0b01000000;
            dots[4] = 0b01000000;
            dots[5] = 0b01000000;
            dots[6] = 0b11100000;
            dots[7] = 0b00000000;
            break;
        case '2':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b00001000;
            dots[3] = 0b01110000;
            dots[4] = 0b10000000;
            dots[5] = 0b10000000;
            dots[6] = 0b11111000;
            dots[7] = 0b00000000;
            break;
        case '3':
            dots[0] = 0b11111000;
            dots[1] = 0b00001000;
            dots[2] = 0b00010000;
            dots[3] = 0b00110000;
            dots[4] = 0b00001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case '4':
            dots[0] = 0b00010000;
            dots[1] = 0b00110000;
            dots[2] = 0b01010000;
            dots[3] = 0b10010000;
            dots[4] = 0b11111000;
            dots[5] = 0b00010000;
            dots[6] = 0b00010000;
            dots[7] = 0b00000000;
            break;
        case '5':
            dots[0] = 0b11111000;
            dots[1] = 0b10000000;
            dots[2] = 0b11110000;
            dots[3] = 0b00001000;
            dots[4] = 0b00001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case '6':
            dots[0] = 0b00111000;
            dots[1] = 0b01000000;
            dots[2] = 0b10000000;
            dots[3] = 0b11110000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case '7':
            dots[0] = 0b11111100;
            dots[1] = 0b00000100;
            dots[2] = 0b00001000;
            dots[3] = 0b00010000;
            dots[4] = 0b00100000;
            dots[5] = 0b01000000;
            dots[6] = 0b10000000;
            dots[7] = 0b00000000;
            break;
        case '8':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b01110000;
            dots[4] = 0b10001000;
            dots[5] = 0b10001000;
            dots[6] = 0b01110000;
            dots[7] = 0b00000000;
            break;
        case '9':
            dots[0] = 0b01110000;
            dots[1] = 0b10001000;
            dots[2] = 0b10001000;
            dots[3] = 0b01111000;
            dots[4] = 0b00001000;
            dots[5] = 0b00010000;
            dots[6] = 0b11100000;
            dots[7] = 0b00000000;
            break;
        default:
            break;
    }

    uint8_t col, bit, dot_x, dot_y;
    uint8_t *dots_p = dots;

    for (col = 0; col < CHARA_HEIGHT; ++col, ++dots_p) {
        if (*dots_p == 0) {
            continue;
        }

        dot_x = x + 7 - col;

        for (bit = 0, dot_y = y; bit < CHARA_WIDTH; ++bit, ++dot_y) {
            if ((*dots_p >> (7 - bit)) & 1) {
                screen_draw_bit(matrix, dot_x, dot_y);
            }
        }
    }
}

void print_chara_p(struct ScreenMatrix *matrix, char *str, uint8_t row) {
    const uint8_t x            = DisplayHeight - (row + 1) * CHARA_HEIGHT;
    const uint8_t chara_length = strlen(str);

    for (uint8_t i = 0; i < chara_length; i++, str++) {
        print_chara(matrix, *str, x, i * CHARA_WIDTH);
    }
}