#include "esc.h"
//Initialize for PWM output
int8_t esc_init(void){
    PWM_INIT();
    return ESC_OK;
}

//Starts the clock for PWM
int8_t esc_start(void){
    PWM_START();
    return ESC_OK;
}

//Stops the clock for PWM 
int8_t esc_stop(void){
    PWM_STOP();
    return ESC_OK;
}

//Sets the duty of the PWM as a float from 0.00 to 1.00
int8_t esc_set_duty(PWM_PINS pin, float duty){
    if (duty > 1.0f || duty < 0.0f){
        return ESC_INVALID_DUTY;
    }
    PWM_WRITE(pin, (uint8_t)(duty*255.0f));
    return ESC_OK;
}