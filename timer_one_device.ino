#include <TimerOne.h>
#include "timer_one_device.h"

#include "utility.h"
#include "clock.h"

void TimerOneDevice::init()
{
    Timer1.initialize(5000000); // set a timer of length 5 sec
    //Timer1.attachInterrupt(dumb);
    //Timer1.stop();
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

void dumb()
{
    debugLog("tick ..");
}

