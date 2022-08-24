#include "jw_app.h"

#include "FreeRTOS.h"
#include "task.h"

#include "main.h"
#include "stm32f1xx_hal_iwdg.h"

#define APP_TASK_NAME   "app"
#define APP_STACK_SIZE  128
#define APP_TASK_PRI    1

TaskHandle_t *app_task_handle;
//---------------------------------------------------------------------
static void jw_app_task(void *param);

//---------------------------------------------------------------------
void jw_app_init(void)
{
    extern uint32_t SystemCoreClock;
    jw_printf("%s, SystemCoreClock = %d\n", __func__, SystemCoreClock);

    //load config

    //create task
    if(pdFAIL == xTaskCreate( jw_app_task,
                    APP_TASK_NAME,
                    APP_STACK_SIZE,
                    NULL,
                    APP_TASK_PRI,
                    app_task_handle))
    {
        jw_printf("create app_task fail\n");
    }
}

void jw_app_start(void)
{
    jw_printf("%s\n", __func__);

    vTaskStartScheduler();
}

static void jw_app_task(void *param)
{
    int cnt = 0;
    while(1)
    {
        jw_printf("jw_app_task cnt=%d\n", cnt++);

        extern IWDG_HandleTypeDef hiwdg;
        HAL_IWDG_Refresh(&hiwdg);

        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
}


