#ifndef __PWM_H
#define __PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

extern void setPWMDutyCycle(uint8_t channel, float percent);

#ifdef __cplusplus
}
#endif

#endif /* __PWM_H */