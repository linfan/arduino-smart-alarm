// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

#define HTTP_BUFFER_SIZE 256

class WifiDevice : public INetworkDevice
{
private:
    char m_buf[HTTP_BUFFER_SIZE];
    char* httpGet(char* url);
public:
    void init();
    void step();
    void getNetworkTime(char* timeStr);
    void getNthEvent(int index, Event* event);
};

#endif

