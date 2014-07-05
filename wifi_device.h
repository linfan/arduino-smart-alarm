// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

#define CURL_BUFFER_SIZE 512

class WifiDevice : public INetworkDevice
{
private:
    char m_buf[256];
public:
    void init();
    char* getNetworkTime();
    Event* getNthEvent(int index);
};

#endif























