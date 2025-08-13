/**
 * @file a3144.c
 * @brief Implementation for driver of the A3144 Hall Sensor
 * @author Pradyunn Kale
 * @date 2025-08-09
 */
#include "a3144.h"
#include <stdint.h>
#include <stdbool.h>
//Obtains frequency by getting the time between rising edges'

/**
 * @brief Volatile variables updated by STM32 HAL Functions
 */
volatile uint32_t prev_edge_time = 0;
volatile uint32_t curr_edge_time = 0; 
volatile bool edge_ready = false;

/**
 * @brief Gets the time between pulses
 * 
 * @details This function gets the frequency by computing the time between pulses
 * f = 1/time_between pulses.
 * 
 * @return float Returns the frequency of the pulses per second
 */
float get_frequency(void){
    if (!edge_ready) return 0.0f;
    uint32_t delta_ticks;
    float timer_clock_hz = 1e6f;
    if (curr_edge_time >= prev_edge_time){
        delta_ticks = curr_edge_time - prev_edge_time;
    } else {
        delta_ticks = (0xFFFFFFFF - curr_edge_time) + prev_edge_time + 1;
    }

    edge_ready = false;

    float period_seconds = delta_ticks/timer_clock_hz;
    return 1/period_seconds;
}

/**
 * @brief Converts the frequency to Revolutions Per Minute
 * 
 * @param frequency is the current frequency of pulses per second
 * @param pulses_per_revolution is the number of pulses per revolution
 * @return float Revolutions per minute
 */
float frequency_to_rpm(float frequency, int pulses_per_revolution){
    return (frequency*60)/pulses_per_revolution;
}