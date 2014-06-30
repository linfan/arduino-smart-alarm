#include <TimerOne.h>
#include "timer_one_device.h"

void TimerOneDevice::init()
{
    Timer1.initialize(5000000); // set a timer of length 5 sec
    Timer1.attachInterrupt( tick ); // attach the service routine here
}

void TimerOneDevice::setInterval(int uSec)
{
    Timer1.setPeriod(uSec);
    Timer1.restart();
}

void tick()
{
    // Toggle LED
    digitalWrite( 13, digitalRead( 13 ) ^ 1 );
}













