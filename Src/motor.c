#include "tim.h"
#include "lptim.h"
#include "motor.h"
#include <stdio.h>

void StartMotorTask(void const * argument)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL); // PB12 and PC10
    HAL_LPTIM_Encoder_Start(&hlptim1, 0xffff);      // PC0 and PC2
    // TIM1->ARR is 1000
    TIM1->CCR1= (uint16_t)500;
    TIM1->CCR2= (uint16_t)0;
    TIM1->CCR3= (uint16_t)500;
    TIM1->CCR4= (uint16_t)0;
    uint16_t enc1, enc2;
    for(;;)
    {
        enc1 = (uint16_t)TIM5->CNT;
        enc2 = (uint16_t)LPTIM1->CNT;
        printf("encoder value:\t%d\r\n", enc1);
        printf("LPTIM encoder value:\t%d\r\n", enc2);
        osDelay(500);
    };
}


void setWheelVel(Wheel_LR dir, int8_t cmd)
{

}