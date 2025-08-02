#include "pid.h"

//Initialize the PID control
void PID_INIT(PID_Controller* pid, float Kp, float Ki, float Kd, float target, float dt, float output_min, float output_max){
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->target = target;
    pid->dt = dt;
    pid->output_min = output_min;
    pid->output_max = output_max;
    pid->integral = 0;
    pid->previous_error = 0;
}


//Calculate the error term of the PID
float PID_ComputeError(PID_Controller* pid, float current_rpm){
    return pid->target - current_rpm;
}


//Calculate the output term where the output term = Kp*error + Ki*integral of error + Kd*derivative of error
float PID_ComputeOutput(PID_Controller* pid, float error){
    pid->integral += error*pid->dt;
    float derivative = (error - pid->previous_error)/pid->dt;
    float output = pid->Kp*error + pid->Ki*pid->integral + pid->Kd*derivative;
    
    pid->previous_error = error;

    if (output > pid->output_max) return pid->output_max;
    else if (output < pid->output_min) return pid->output_min;
    else return output;
}