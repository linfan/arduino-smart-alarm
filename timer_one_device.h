#ifndef __SMART_ALARM_TIMER_ONE_DEVICE_H__
#define __SMART_ALARM_TIMER_ONE_DEVICE_H__

#include "device.h"

class TimerOneDevice : public ITimerDevice
{
public:
    void init();
    void setInterval(unsigned long uSec);
    void setInterruptCallback(void (*call)());
    void startTimer();
    void stopTimer();
};

#endif























