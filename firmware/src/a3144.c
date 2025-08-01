#include "a3144_driver.h"
#include <stdint.h>
#include <stdbool.h>
//Obtains frequency by getting the time between rising edges'
volatile uint32_t first_edge_time = 0;
volatile uint32_t last_edge_time = 0; 
volatile bool edge_ready = false;
//These volatile variables are updated by a HAL function which has not been added yet to the code.


float get_frequency(void){
    if (!edge_ready) return 0.0f;
    uint32_t delta_ticks;
    float timer_clock_hz = 1e6f; //1MHz timer clock
    if (last_edge_time >= first_edge_time){
        delta_ticks = last_edge_time - first_edge_time;
    } else {
        delta_ticks = 0xFFFFFFFF - (last_edge_time - first_edge_time) + 1;
    }

    edge_ready = false;

    float period_seconds = delta_ticks/timer_clock_hz;
    return 1/period_seconds;
}

//Converts the frequency to rpm for easy math
float frequency_to_rpm(float frequency, int pulses_per_revolution){
    return (frequency*60)/pulses_per_revolution;
}