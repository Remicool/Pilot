#include "tim.h"
#include "lptim.h"
#include "motor.h"
#include <stdio.h>

// Hall resolution 695
#define ENCODER_ONE_CIRCLE 695.1f

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
    float ang1, ang2;
    for(;;)
    {
        ang1 = TIM5->CNT  / ENCODER_ONE_CIRCLE;
        ang2 = LPTIM1->CNT/4  / ENCODER_ONE_CIRCLE;
        printf("encoder value:      \t%f\r\n", ang1);
        printf("LPTIM encoder value:\t%f\r\n", ang2);
        osDelay(500);
    };
}


void setWheelVel(Wheel_LR dir, int8_t cmd)
{

}