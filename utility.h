#ifndef __SMART_ALARM_UTILITY_H__
#define __SMART_ALARM_UTILITY_H__

#define DEBUG 1

#if DEBUG
#define initSerialForDebug() Serial.begin(9600);
#define debugLog(data)  Serial.println(data); Serial.flush();
#define debugPrint(data)  Serial.print(data); Serial.flush();
#else
#define initSerialForDebug()
#define debugLog(data)
#define debugPrint(data)
#endif

#endif

