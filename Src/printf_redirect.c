#include <stdio.h>
#include "stm32f4xx_hal.h"

// For debug out put to SWO
int _write(int file, char *ptr, int len)
{
  /* Implement your write code here, this is used by puts and printf for example */
  int i=0;
  for(i=0 ; i<len ; i++) 
    ITM_SendChar((*ptr++));
  return len;
}