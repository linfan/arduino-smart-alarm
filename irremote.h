#ifndef __SMART_ALARM_IRREMOTE_H__
#define __SMART_ALARM_IRREMOTE_H__

// Arduino digital pin connected to IR receiver
#define RECEIVER_PIN 7

void initIrRemote();
char translateIR();
char readIrRemote();

#endif
