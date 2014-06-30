#ifndef __SMART_ALARM_TIMER_ONE_DEVICE_H__
#define __SMART_ALARM_TIMER_ONE_DEVICE_H__

#include "device.h"

class TimerOneDevice : public ITimerDevice
{
public:
    void init();
    void setInterval(int uSec);
  
};

#endif













