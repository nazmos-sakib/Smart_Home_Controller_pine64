#include <stdio.h>

#include <FreeRTOS.h>
#include <task.h>

#include <lwip/apps/httpd.h>

#include "cgi.h"
//#include "adc.h"


void task_adc_init();


void task_httpd(void *pvParameters)
{
  /* wait for half a second */
  printf("Starting up httpd\r\n");
  
  //
  task_adc_init();
  //
  httpd_init();
  
  /* initialize CGI */
  custom_files_init();
  cgi_init();
  while(1) {
    printf("httpd keepalive\r\n");
    vTaskDelay(5*60*1000);
  }
  
  /* will never happen */
  vTaskDelete(NULL);
}

