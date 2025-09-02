/**
 * @file a3144.h
 * @brief Header for the driver of the A3144 Hall Sensor
 * @author Pradyunn Kale
 * @date 2025-08-09
 */
#pragma once
#define TIME_OF_RISING_EDGE()

float get_frequency(void);
float frequency_to_rpm(float frequency, int pulses_per_revolution);
float get_current_angle(float frequency);
