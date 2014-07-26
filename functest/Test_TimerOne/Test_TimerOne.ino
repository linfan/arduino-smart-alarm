#include <TimerOne.h>

void initTimer()
{
}

void setInterval(unsigned long uSec)
{
    Timer1.setPeriod(uSec);
}

void setInterruptCallback(void (*call)())
{
    Timer1.attachInterrupt(call);
}

void startTimer()
{
    Timer1.resume();
}

void stopTimer()
{
    Timer1.stop();
}

void dumb()
{
    Serial.println("tick >>");
}

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    Timer1.initialize(1000000); // set a timer of length 1 sec
    stopTimer();
    setInterruptCallback(dumb);
    setInterval(2000000);  // change interval to 2 seconds
    startTimer();
    Serial.println("setup ##");
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(1000);
    Serial.println("<< tack");
}

