#pragma once

#include "../screen.h"
#include <avr/pgmspace.h>

void print_digimon(ScreenMatrix *screen, const uint8_t dots[][2], uint8_t x, uint8_t y, bool mirror);
