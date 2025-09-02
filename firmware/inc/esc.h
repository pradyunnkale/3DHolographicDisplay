#pragma once
#include <stdint.h>

#define PWM_START() //Abstracted, will add once all main functions are done
#define PWM_STOP() //Abstracted, will add once all main functions are done
#define PWM_WRITE(pin, value) //Abstracted, will add once all main functions are done
#define PWM_INIT() //Abstracted, will add once all main functions are done

//Will actually set values once I get my NUCLEO board
typedef enum{
    PWM1,
    PWM2,
    PWM3,
    PWM4,
}PWM_PINS;

//Error codes so user knows what function has an error
typedef enum{
    ESC_OK = 0,
    ESC_INVALID_DUTY = -1,
    ESC_INVALID_PIN = -2
}ERROR_CODES;

int8_t esc_init(void); //Initialize the ESC
int8_t esc_start(void); //Start the ESC
int8_t esc_stop(void); //Stop the ESC
int8_t esc_set_duty(PWM_PINS pin, float duty); //Set duty for the esc