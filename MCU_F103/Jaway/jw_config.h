#ifndef __JW_CONFIG_H
#define __JW_CONFGI_H

#include "SEGGER_RTT.h"

#define jw_printf(fmt, ...) SEGGER_RTT_printf(0, fmt, ##__VA_ARGS__)











#endif
