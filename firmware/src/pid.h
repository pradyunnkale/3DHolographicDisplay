#pragma once

typedef struct{
    float Kp, Ki, Kd;

    float target;

    float previous_error;
    float integral;

    float dt;

    float output_min, output_max;
}PID_Controller;

void PID_INIT(PID_Controller* pid, float Kp, float Ki, float Kd, float target, float output_min, float output_max);
float PID_ComputeError(PID_Controller* pid, float current_rpm);
float PID_ComputeOutput(PID_Controller* pid, float error); 