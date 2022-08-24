#ifndef __JW_CONFIG_H
#define __JW_CONFGI_H

#include "SEGGER_RTT.h"

#define jw_printf(fmt, ...) SEGGER_RTT_printf(0, fmt, ##__VA_ARGS__)



/*
    ----------FLASH CONFIG------------
    FLASH_BASE          0X0800 0000
    FLASH_MAX_SIZE      0X0004 0000 //256

    FLASH_IAP_ADDR      FLASH_BASE
    IAP_CODE_MAX_SIZE   0X0000 4000 //16k
    FLASH_CONFIG_ADDR   0X0800 4000 
    FLASH_CONFIG_SIZE   0X0000 1000 //4k

    FLASH_APP_ADDR      0X0800 5000
    APP_MAX_SIZE        0X0001 D800 //118K
    FLASH_IMG_ADDR      0X0802 2800
    IMG_MAX_SIZE        APP_MAX_SIZE

    #define APP_OTA_FLAG_ADDR    (0x803FC00) //old
*/

#define FLASH_APP_ADDR 0x08005000





#endif
