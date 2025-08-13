#pragma once
#include <stdint.h>

typedef struct {
    int r;
    int z;
    int w;
}Positon_Vector_t;

int8_t led_on();
int8_t led_off();
int8_t led_set_array(); 