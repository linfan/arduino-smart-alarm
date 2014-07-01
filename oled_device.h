#ifndef __SMART_ALARM_OLED_DEVICE_H__
#define __SMART_ALARM_OLED_DEVICE_H__

#include <U8glib.h>
#include "device.h"
#include "config.h"

// 1.3" OLED
class OledDevice : public IDisplayDevice
{
    DRAW_HANDLER* u8g;

public:
    OledDevice();
    
    void init();
    void show(IDrawable*);
};

#endif

















