#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

#include "config.h"
#include "event.h"
#include "notification.h"

class IDevice {
public:
    virtual void init() = 0;
    virtual void step() = 0;
    virtual void notify(Notification*) = 0;
};

class IDisplayDevice : public IDevice {
};

class IKeyboardDevice : public IDevice {
public:
    virtual char getChar() = 0;
};

class INetworkDevice : public IDevice {
};

class ITimerDevice : public IDevice {
};

#endif

