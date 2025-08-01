# 3D Holographic Display Project

This project implements a 3D holographic display system using STM32 microcontrollers. It combines hardware PWM control, sensor input, and custom electronics to create a volumetric display.

## Project Overview

The system leverages:

- STM32 MCU (e.g., NUCLEO-H753ZI)
- PWM-driven electronics to control holographic projection elements
- Sensor drivers (e.g., A3144 Hall sensor) for rotation and timing feedback
- Custom ESC drivers for motor and display control

## Features

- Precise PWM control for hologram projection
- Real-time frequency measurement for synchronization
- Modular and hardware-abstracted firmware components

## Hardware Setup

- STM32 NUCLEO-H753ZI board or equivalent
- Custom PCB for holographic display components
- ESC and brushless DC motor for rotation
- A3144 Hall sensor for rotational speed feedback

## Getting Started

### Prerequisites

- STM32CubeIDE or ARM GCC toolchain
- STM32 HAL libraries

### Build Instructions

Use the provided Makefile or IDE project to build firmware:

```bash
make
