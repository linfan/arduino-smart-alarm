// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

#define HTTP_BUFFER_SIZE 256
#define NOTIFY_HEAD_TIME 300L  // 5 mins
#define UPDATE_INTERVAL 600L   // 10 mins
#define WIFI_DEBUG 1

enum WifiState
{
    WIFI_IDLE,
    WIFI_INIT_TIME,
    WIFI_WAITING,
    WIFI_FETCH_EVENT,
    WIFI_WAIT_EVENT_FINISH
};

class WifiDevice : public INetworkDevice
{
private:
    char m_buf[HTTP_BUFFER_SIZE];
    WifiState m_wifiState;
    Event* m_nextEvent;
    unsigned long m_lastUpdateEventTime;
    char* httpGet(char* url);
    void initLocalTime();
    void updateEvent();
    void checkEvent();
    void waitEventFinish();
public:
    WifiDevice();
    void init();
    void step();
    void notify(Notification*);
    void getNetworkTime(char* timeStr);
    void getNthEvent(int index, Event* event);
};

#endif

