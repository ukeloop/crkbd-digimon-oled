#include "digimon.h"

#include "sprite/digiegg.c"
#include "sprite/botamon.c"
#include "sprite/koromon.c"

#include "sprite/guilmon.c"
#include "sprite/growlmon.c"
#include "sprite/wargrowlmon.c"
#include "sprite/gallantmon.c"

#include "sprite/betamon.c"
#include "sprite/airdoramon.c"
#include "sprite/megadramon.c"
#include "sprite/megidramon.c"

extern FUNCPTR digimon_print_function;

extern char digimon_name[24];

void set_digimon_master(uint16_t *frame) {
#ifdef WPM_ENABLE
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
        if (get_current_wpm() > 30) {
            strcpy(digimon_name, "Betamon");
            digimon_print_function = &print_betamon;
        } else {
            strcpy(digimon_name, "Guilmon");
            digimon_print_function = &print_guilmon;
        }
    } else if (*frame == ADULT_AGE) {
        if (get_current_wpm() > 30) {
            strcpy(digimon_name, "Airdoramon");
            digimon_print_function = &print_airdoramon;
        } else {
            strcpy(digimon_name, "Growmlon");
            digimon_print_function = &print_growlmon;
        }
    } else if (*frame == PERFECT_AGE) {
        if (get_current_wpm() > 30) {
            strcpy(digimon_name, "Megadramon");
            digimon_print_function = &print_megadramon;
        } else {
            strcpy(digimon_name, "WarGrowlmon");
            digimon_print_function = &print_wargrowlmon;
        }
    } else if (*frame == ULTIMATE_AGE) {
        if (get_current_wpm() > 30) {
            strcpy(digimon_name, "Megidramon");
            digimon_print_function = &print_megidramon;
        } else {
            strcpy(digimon_name, "Gallantmon");
            digimon_print_function = &print_gallantmon;
        }
    }
#else
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
        strcpy(digimon_name, "Guilmon");
        digimon_print_function = &print_guilmon;
    } else if (*frame == ADULT_AGE) {
        strcpy(digimon_name, "Growmlon");
        digimon_print_function = &print_growlmon;
    } else if (*frame == PERFECT_AGE) {
        strcpy(digimon_name, "Megadramon");
        digimon_print_function = &print_megadramon;
    } else if (*frame == ULTIMATE_AGE) {
        strcpy(digimon_name, "Gallantmon");
        digimon_print_function = &print_gallantmon;
    }
#endif
}