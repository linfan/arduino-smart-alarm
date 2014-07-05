#ifndef __SMART_ALARM_SERIAL_AND_LED_H__
#define __SMART_ALARM_SERIAL_AND_LED_H__

#define DEBUG 1

#if DEBUG
#define initSerialForDebug() Serial.begin(9600);
#define debugLog(data)  Serial.println(data); Serial.flush();
#else
#define initSerialForDebug()
#define debugLog(data)
#endif

#endif























