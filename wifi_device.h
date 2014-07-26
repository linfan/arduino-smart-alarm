// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

#define HTTP_BUFFER_SIZE 256

enum WifiState
{
    WIFI_IDLE,
    WIFI_INIT_TIME,
    WIFI_FETCH_EVENT
};

class WifiDevice : public INetworkDevice
{
private:
    char m_buf[HTTP_BUFFER_SIZE];
    WifiState m_wifiState;
    Event* m_nextEvent;
    char* httpGet(char* url);
    void initLocalTime();
    void updateEvent();
public:
    WifiDevice();
    void init();
    void step();
    void notify(Notification*);
    void getNetworkTime(char* timeStr);
    void getNthEvent(int index, Event* event);
};

#endif

