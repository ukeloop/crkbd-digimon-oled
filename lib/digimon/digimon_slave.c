#include "digimon.h"

#include "sprite/digiegg.c"
#include "sprite/botamon.c"
#include "sprite/koromon.c"

#include "sprite/gabumon.c"
#include "sprite/garurumon.c"
#include "sprite/weregarurumon.c"
#include "sprite/metalgarurumon.c"

extern char digimon_name[24];

void set_digimon_slave(uint16_t *frame) {
    if (*frame == 0) {
        strcpy(digimon_name, "Digi-Egg");
        digimon_print_function = &print_digiegg;
    } else if (*frame == FRESH_AGE - FPS) {
        digimon_print_function = &print_digiegg_birth;
    } else if (*frame == FRESH_AGE) {
        strcpy(digimon_name, "Botamon");
        digimon_print_function = &print_botamon;
    } else if (*frame == BADY_AGE) {
        strcpy(digimon_name, "Koromon");
        digimon_print_function = &print_koromon;
    } else if (*frame == CHILD_AGE) {
        strcpy(digimon_name, "Gabumon");
        digimon_print_function = &print_gabumon;
    } else if (*frame == ADULT_AGE) {
        strcpy(digimon_name, "Garurumon");
        digimon_print_function = &print_garurumon;
    } else if (*frame == PERFECT_AGE) {
        strcpy(digimon_name, "WereGarurumon");
        digimon_print_function = &print_weregarurumon;
    } else if (*frame == ULTIMATE_AGE) {
        strcpy(digimon_name, "MetalGarurumon");
        digimon_print_function = &print_metalgarurumon;
    }
}