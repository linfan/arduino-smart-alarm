#ifndef __SMART_ALARM_TIMER_DEVICE_H__
#define __SMART_ALARM_TIMER_DEVICE_H__

#include "device.h"

class TimerDevice : public ITimerDevice
{
public:
    TimerDevice();
    ~TimerDevice();
    
    void init();
    void setInterval(int uSec);
  
};

#endif

