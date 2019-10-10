#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

// LEFT: Encoder lptim1, PWM CH1/2
// RIGHT:Encoder tim5,   PWM CH3/4
typedef enum Wheel_LR{
    WHEEL_LEFT,     
    WHEEL_RIGHT     
}Wheel_LR;

extern void carForward(int cm);
extern void carBackward(int cm);
extern void carTurnLeft(int deg);
extern void carTurnRight(int deg);

// dir = WHEEL_LEFT/WHEEL_RIGHT
// cmd <= 32767 >=-32767
void setWheelVel(Wheel_LR dir, int16_t cmd);

// dir = WHEEL_LEFT/WHEEL_RIGHT
float getWheelAngDeg(Wheel_LR dir);

// dir = WHEEL_LEFT/WHEEL_RIGHT
// need 1ms
static float getWheelVelDeg(Wheel_LR dir);

typedef struct PID_Controller{
    float kp;
    float ki;
    float kd;
    float iMax;
    float inte;
}PID_Controller_t;


#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_H */
