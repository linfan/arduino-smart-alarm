// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

class WifiDevice : public INetworkDevice
{
private:
    char m_buf[256];
    char* httpGet(char* url);
public:
    void init();
    char* getNetworkTime();
    Event* getNthEvent(int index);
};

#endif



























