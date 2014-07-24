#include <TimerOne.h>
#include "timer_one_device.h"

#include "utility.h"
#include "clock.h"

#define print_current_time() \
    char strTime[26]; \
    Clock::ToStandardTime(Clock::Ins()->getTime(), strTime); \
    debugLog(strTime);

void TimerOneDevice::init()
{
    stopTimer();
    setInterval(5000000); // set a timer of length 5 sec
    setInterruptCallback(tick);
    startTimer();
}

void TimerOneDevice::step()
{
}

void TimerOneDevice::setInterval(unsigned long uSec)
{
    Timer1.setPeriod(uSec);
}

void TimerOneDevice::setInterruptCallback(void (*call)())
{
    Timer1.attachInterrupt(call);
}

void TimerOneDevice::startTimer()
{
    Timer1.resume();
}

void TimerOneDevice::stopTimer()
{
    Timer1.stop();
}

void tick()
{
    Clock::Ins()->increaseTime(5);
    //print_current_time();
}

