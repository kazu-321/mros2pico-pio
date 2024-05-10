#include "lwip/lwip.h"
#include "lwip/lwipopts.h"
#include "cmsis/cmsis_os.h"
#include <FreeRTOS.h>
#include <semphr.h>
#include <stdio.h>

static SemaphoreHandle_t xMutex = NULL;

void MX_LWIP_Init(void)
{
  xMutex = xSemaphoreCreateMutex();
  return;
}

void sys_lock_tcpip_core(void)
{
  xSemaphoreTake(xMutex, portMAX_DELAY);
  return;
}

void sys_unlock_tcpip_core(void)
{
  xSemaphoreGive(xMutex);
  return;
}
