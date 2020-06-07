#pragma once

#include "../screen.h"
#include "../string/print_chara.h"

#ifndef IS_MASTER
#define IS_MASTER 0
#endif

#define FPS 60
#define REFRESH_INTARVAL 1000 / FPS
#define FRESH_AGE 2 * FPS
#define BADY_AGE 10 * FPS
#define CHILD_AGE 25 * FPS
#define ADULT_AGE 80 * FPS
#define PERFECT_AGE 130 * FPS
#define ULTIMATE_AGE 180 * FPS
#define MAX_AGE 255 * FPS

#define DIGIMON_W 16
#define DIGIMON_H 16

#define DIGIMON_MIN_X 0
#define DIGIMON_MAX_X DisplayHeight - DIGIMON_W
#define DIGIMON_Y DisplayWidth - DIGIMON_H

typedef void (*FUNCPTR)(struct ScreenMatrix *matrix, uint8_t sprite_id, uint8_t x, uint8_t y, bool mirror);
extern FUNCPTR digimon_print_function;

void draw_digimon_handler(struct ScreenMatrix *matrix);
