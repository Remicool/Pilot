#ifndef __UART_H
#define __UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"
#include "stm32f4xx_hal.h"

osThreadId uartTaskHandle;

void StartUartTask(void const * argument);

#ifdef __cplusplus
}
#endif

#endif /* __UART_H */