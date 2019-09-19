#include "uart.h"

UART_HandleTypeDef huart1;
void StartUartTask(void const * argument)
{
    char data[] = "uart1 test!\n";
    for(;;)
    {
        HAL_UART_Transmit(&huart1,(uint8_t*) data, sizeof(data), 1000);
        osDelay(500);
    }
}
