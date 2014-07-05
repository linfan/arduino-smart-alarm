#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

#include "config.h"
#include "event.h"
#include "drawable.h"

class IDevice {
public:
    virtual void init() = 0;
};

class IDisplayDevice : public IDevice {
public:
    virtual void show(IDrawable*) = 0;
};

class IKeyboardDevice : public IDevice {
public:
    virtual char getChar() = 0;
};

class INetworkDevice : public IDevice {
public:
    virtual char* getNetworkTime() = 0;
    virtual Event* getNthEvent(int) = 0;
};

class ITimerDevice : public IDevice {
public:
    virtual void setInterval(unsigned long uSec) = 0;
    virtual void setInterruptCallback(void (*call)()) = 0;
    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
};

#endif


















