#include <TimerOne.h>
#include "timer_one_device.h"

#include "utility.h"
#include "clock.h"

#define print_current_time() \
    Clock::ToStandardTime(Clock::Ins()->getTime(), p_buf); \
    debugPrint(p_buf); \
    debugPPrint(" => "); \
    debugLog(Clock::Ins()->getTime());

void TimerOneDevice::init()
{
    Timer1.initialize(1000000);
    Timer1.stop();
}

void TimerOneDevice::step()
{}

void tick()
{
    Clock::Ins()->increaseTime(5);
    print_current_time();
}

void TimerOneDevice::beginTick()
{
    Timer1.attachInterrupt(tick);
    Timer1.setPeriod(5000000); // set a timer of length 5 sec
    Timer1.resume();
}

void TimerOneDevice::notify(Notification* noti)
{ 
    switch(noti->type)
    {
    case NOTI_INIT_FINISH:
        beginTick();
        break;
    }
}

