#include "tim.h"
#include "pwm.h"

void StartPWMTask(void const * argument)
{
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
    for(;;);
}

void setPWMDutyCycle(uint8_t channel, float percent)
{
    switch (channel)
    {
    case 1:
        TIM5->CCR1 = (uint16_t)percent * 500/100;
        break;
    case 2:
        TIM5->CCR2 = (uint16_t)percent * 500/100;
        break;
    case 3:
        TIM5->CCR3 = (uint16_t)percent * 500/100;
        break;
    case 4:
        TIM5->CCR4 = (uint16_t)percent * 500/100;
        break;
    default:
        break;
    }
}