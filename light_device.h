#ifndef __SMART_ALARM_LIGHT_DEVICE_H__
#define __SMART_ALARM_LIGHT_DEVICE_H__

#include "device.h"
#include "notification.h"

enum LightState
{
    LIGHT_IDLE,
    LIGHT_UP,
    LIGHT_DONW
};

class LightDevice : public IDevice
{
    LightState m_lightState;
    void lightUp();
    void lightDown();
    
public:
    LightDevice();

    void init();
    void step();
    void notify(Notification*);
};

#endif