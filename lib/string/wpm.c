#ifdef WPM_ENABLE

#include <stdio.h>
#include "crkbd.h"

static uint8_t current_wpm = 0;
static uint8_t latest_wpm = 0;

static char wpm_str[24] = {};

const char *get_wpm(void) {
    latest_wpm = get_current_wpm();
    if (current_wpm != latest_wpm) {
        current_wpm = latest_wpm;
        sprintf(wpm_str, "WPM:%d", current_wpm);
    }
    return wpm_str;
}
#endif 