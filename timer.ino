#include <TimerOne.h>
#include "timer.h"

void initInternalTimer()
{
  Timer1.initialize(5000000); // set a timer of length 5 sec
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
}

void timerIsr()
{
    // Toggle LED
    digitalWrite( 13, digitalRead( 13 ) ^ 1 );
}
