#include <stdio.h>
#include "crkbd.h"

static char keylog_str[24] = {};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    static const char code_to_name[60] = {
        ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' ',
    };

    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col, keycode,
           keycode < 60 ? code_to_name[keycode] : ' ');
}

const char *get_keylog(void) {
    return keylog_str;
}