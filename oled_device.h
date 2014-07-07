#ifndef __SMART_ALARM_OLED_DEVICE_H__
#define __SMART_ALARM_OLED_DEVICE_H__

#include <U8glib.h>
#include "device.h"
#include "config.h"

#define BEGIN_POS_X   2
#define BEGIN_POS_Y   6
#define LINE_WIDTH    21
#define LINE_HIGHT    12

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

