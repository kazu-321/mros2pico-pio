#ifndef MROS2_PLATFORM_H
#define MROS2_PLATFORM_H

#include "cmsis/cmsis_os.h"
#include "wifi/wifi.c"

/* convert TARGET_NAME to put into message */
#define quote(x) std::string(q(x))
#define q(x) #x


/* NOTE: this function has not been implemented and used yet */
extern "C" esp_err_t mros2_platform_network_connect(void);


#endif /* MROS2_PLATFORM_H */