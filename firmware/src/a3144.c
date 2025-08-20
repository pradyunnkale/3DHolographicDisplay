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
 * @brief Variables updated by STM32 HAL Functions
 */
volatile uint32_t prev_edge_ticks = 0;
volatile uint32_t curr_edge_ticks = 0; 
volatile bool edge_ready = false;
uint32_t curr_ticks = 0;
const timer_clock_hz = 1e6f;

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
    if (curr_edge_ticks >= prev_edge_ticks){
        delta_ticks = curr_edge_ticks - prev_edge_ticks;
    } else {
        delta_ticks = (1e0xFFFFFFFF - curr_edge_ticks) + prev_edge_ticks + 1;
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
/**
 * @brief Gets current angle of the motor, extremely helpful for LED calling
 *
 * @param frequency is the current frequency of pulses per second
 * @return float Current Angle of the motor
 */
float get_current_angle(float frequency) {
    float current_time = curr_ticks/timer_clock_hz;
    float time_since_last_edge = current_time - curr_edge_ticks/timer_clock_hz;
    return time_since_last_edge*frequency * 360;
}
