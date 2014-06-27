#ifndef __SMART_ALARM_OLED_DEVICE_H__
#define __SMART_ALARM_OLED_DEVICE_H__

#include "device.h"

#define D0_PIN   10
#define D1_PIN   9
#define CS_PIN   12
#define DC_PIN   11
#define RST_PIN  13

class OledDevice : public IDisplayDevice
{
public:
    OledDevice();
    ~OledDevice();

    void init();
    void draw(void (*method)(void));
};

#endif

