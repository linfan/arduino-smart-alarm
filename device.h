#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

#include "config.h"
#include "notification.h"

class IDevice {
public:
    virtual void init() = 0;
    virtual void step() = 0;
    virtual void notify(Notification*) = 0;
};

#endif

