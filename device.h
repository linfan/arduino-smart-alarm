#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

#include "drawable.h"

class IDevice {
public:
    virtual void init() = 0;
};

class IDisplayDevice : public IDevice {
public:
    virtual void draw(IDrawable*) = 0;
    //virtual DRAW_HANDLER* getDrawHandler() = 0;
};

class IKeyboardDevice : public IDevice {
public:
    virtual char getChar() = 0;
};

class INetworkDevice : public IDevice {
public:
    virtual char* httpGet(char* url) = 0;
};

class ITimerDevice : public IDevice {
public:
    virtual void setInterval(int uSec) = 0;
};

class IRealTimeDevice : public IDevice {
public:
    virtual unsigned long getCurTime() = 0;
};

#endif











