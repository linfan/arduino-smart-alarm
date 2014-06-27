#ifndef __SMART_ALARM_DEVICE_H__
#define __SMART_ALARM_DEVICE_H__

class IDevice {
    virtual void init() = 0;
};

class IDisplayDevice : public IDevice {
    virtual void draw(void (*method)(void)) = 0;
};

class IKeyboardDevice : public IDevice {
    virtual char getChar() = 0;
};

class INetworkDevice : public IDevice {
    virtual char* httpGet(char* url) = 0;
};

class ITimerDevice : public IDevice {
    virtual void setInterval(int uSec) = 0;
};

#endif

