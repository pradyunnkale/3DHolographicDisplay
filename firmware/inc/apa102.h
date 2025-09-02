#pragma once
#include <stdint.h>
#include <stdbool.h>

#define MAX_R 3
#define MAX_THETA 360
#define LEDS_PER_STRIP 32
#define STRIPS_PER_LAYER 2 
#define APA_OK 0
#define APA_ERR 1

const bool led_map[MAX_R][MAX_THETA][LEDS_PER_STRIP];

typedef struct {
    uint8_t r;
    uint16_t theta0;
    uint8_t z;
    bool status;
}led_state;

uint8_t create_led(uint8_t r, uint8_t z, uint8_t strip_index);
uint8_t led_set(led_state* led);
