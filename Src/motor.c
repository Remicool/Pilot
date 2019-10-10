#include "tim.h"
#include "lptim.h"
#include "motor.h"
#include <stdio.h>

// Hall resolution 695
#define ENCODER_ONE_CIRCLE 695.1f

const PID_Controller_t pid[2] = {0};

void StartMotorTask(void const * argument)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL); // PB12 and PC10
    HAL_LPTIM_Encoder_Start(&hlptim1, 0xffff);      // PC0 and PC2

    setWheelVel(WHEEL_LEFT,20000);
    setWheelVel(WHEEL_RIGHT,-20000);
    float ang1, ang2;
    for(;;)
    {
        ang1 = getWheelAngDeg(WHEEL_LEFT);
        ang2 = getWheelAngDeg(WHEEL_RIGHT);
        getWheelVelDeg(WHEEL_LEFT);
        printf("LPTIM deg value: %f\r\n", ang1);
        printf("TIM5  deg value: %f\r\n", ang2);
        osDelay(500);
    };
}


void setWheelVel(Wheel_LR dir, int16_t cmd)
{
    cmd = cmd>32767?32767:cmd;
    cmd = cmd<-32767?-32767:cmd;
    if(dir==WHEEL_LEFT)
    {
        TIM1->CCR1=(uint16_t)cmd>0?cmd:0;
        TIM1->CCR2=(uint16_t)cmd>0?0:-cmd;
        return;
    }
    if(dir==WHEEL_RIGHT)
    {
        TIM1->CCR3=(uint16_t)cmd>0?cmd:0;
        TIM1->CCR4=(uint16_t)cmd>0?0:-cmd;
        return;
    }
}

float getWheelAngDeg(Wheel_LR dir)
{
    return (float)(dir==WHEEL_LEFT?
    LPTIM1->CNT/4 / ENCODER_ONE_CIRCLE * 360:
    TIM5->CNT /ENCODER_ONE_CIRCLE * 360);
}

float getWheelVelDeg(Wheel_LR dir)
{
    float v = getWheelAngDeg(dir);
    osDelay(1);
    return (getWheelAngDeg(dir) - v)*1000.0f;
}

