# Project Design Document

## Overview
This project implements firmware components for controlling an Electronic Speed Controller (ESC) and reading rotational speed from an A3144 Hall effect sensor. It targets STM32 microcontrollers (e.g., NUCLEO-H753ZI) and provides modular drivers and utilities to manage PWM signals and frequency measurement.

---

## Components

### 1. ESC Driver (`esc.c` / `esc.h`)
- Initializes and controls PWM signals to drive ESC.
- Supports setting duty cycle as a float between 0.0 and 1.0.
- Abstracted hardware interface macros for easy porting to different STM32 boards.
- Functions:
  - `esc_init()`
  - `esc_start()`
  - `esc_stop()`
  - `esc_set_duty(PWM_PINS pin, float duty)`

---

### 2. A3144 Hall Sensor Driver (`a3144.c` / `a3144.h`)
- Measures frequency of pulses from the A3144 Hall effect sensor.
- Uses STM32 timer input capture mode to accurately measure time between rising edges.
- Converts pulse frequency to RPM considering pulses per revolution.
- Functions:
  - `float get_frequency(void)`
  - `float frequency_to_rpm(float frequency, int pulses_per_revolution)`

---

## Hardware

- Target Board: STM32 NUCLEO-H753ZI (or similar STM32 MCU)
- ESC connected to PWM-capable pins.
- A3144 sensor output connected to GPIO pin configured for input capture or EXTI interrupts.
- Timer configured with 1 MHz clock for precise timing.

---

## Software Design

- Use STM32 HAL library for hardware abstraction.
- Interrupt-driven input capture for timing sensor pulses.
- Use volatile variables and proper interrupt-safe access patterns for shared data.
- Modular design for easy expansion and maintenance.

---

## Future Work

- Implement calibration routines for ESC duty cycle to PWM mapping.
- Add error handling and diagnostics in ESC driver.
- Integrate with a higher-level motor control algorithm.
- Add unit tests and CI integration.

---

## References

- STM32 HAL documentation  
- A3144 Hall Effect Sensor datasheet  
- STM32 Timer Input Capture examples  

---

*Last updated: 2025-07-31*

