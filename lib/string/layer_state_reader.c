
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ADJUST_TRI 14

static char   layer_state_str[24];
static uint8_t current_layer_state = 255;

const char *get_layer_state(void) {
    if (current_layer_state == layer_state) {   
        return layer_state_str;
    }

    switch (layer_state) {
        case L_BASE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
            break;
        case L_RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
            break;
        case L_LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
            break;
        case L_ADJUST:
        case L_ADJUST_TRI:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    }

    current_layer_state = layer_state;

    return layer_state_str;
}
