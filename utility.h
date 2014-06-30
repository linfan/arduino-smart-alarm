#ifndef __SMART_ALARM_SERIAL_AND_LED_H__
#define __SMART_ALARM_SERIAL_AND_LED_H__

#define DEBUG 1

void initSerialForDebug();
void debugLog(char* str);
void initLedOnPin13();
void debugLedOn();
void debugLedOff();

#endif













