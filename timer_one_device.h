#ifndef __SMART_ALARM_TIMER_ONE_DEVICE_H__
#define __SMART_ALARM_TIMER_ONE_DEVICE_H__

#include "device.h"

class TimerOneDevice : public IDevice
{
    void beginTick();
public:
    void init();
    void step();
    void notify(Notification*);
};

#endif

