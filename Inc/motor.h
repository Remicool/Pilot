#ifndef __MOTOR_H
#define __MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

typedef enum{
    WHEEL_LEFT,
    WHEEL_RIGHT
} Wheel_LR;

extern void setWheelVel(Wheel_LR dir, int8_t cmd);

#ifdef __cplusplus
}
#endif

#endif /* __MOTOR_H */
