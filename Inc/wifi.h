#ifndef __WIFI_H
#define __WIFI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cmsis_os.h"
#include <stdio.h>

osThreadId wifiTaskHandle;

void StartWifiTask(void const * argument);

#ifdef __cplusplus
}
#endif

#endif /* __WIFI_H */