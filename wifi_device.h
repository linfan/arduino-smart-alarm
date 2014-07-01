// HTTP download
#ifndef __SMART_ALARM_WIFI_DEVICE_H__
#define __SMART_ALARM_WIFI_DEVICE_H__

#include "device.h"

#define CURL_BUFFER_SIZE 512

class WifiDevice : public INetworkDevice
{
public:
    void init();
    char* httpGet(char* url);
};

#endif

















