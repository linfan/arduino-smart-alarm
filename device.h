#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

#include "config.h"
#include "event.h"
#include "notification.h"

class IDevice {
public:
    virtual void init() = 0;
    virtual void step() = 0;
};

class INotificationDevice : public IDevice
{
public:
    virtual void notify(Notification*) = 0;
};

class IDisplayDevice : public INotificationDevice {
public:
    //virtual void show(IDrawable*) = 0;
};

class IKeyboardDevice : public IDevice {
public:
    virtual char getChar() = 0;
};

class INetworkDevice : public IDevice {
public:
    virtual void getNetworkTime(char*) = 0;
    virtual void getNthEvent(int, Event*) = 0;
};

class ITimerDevice : public IDevice {
public:
    virtual void setInterval(unsigned long uSec) = 0;
    virtual void setInterruptCallback(void (*call)()) = 0;
    virtual void startTimer() = 0;
    virtual void stopTimer() = 0;
};

#endif

