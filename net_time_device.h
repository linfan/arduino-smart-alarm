#ifndef __SMART_ALARM_NET_TIME_DEVICE_H__
#define __SMART_ALARM_NET_TIME_DEVICE_H__

#include "device.h"
#include "config.h"

class NetTimeDevice : public IRealTimeDevice
{
public:
    void init();
    unsigned long getCurTime();
};

#endif













