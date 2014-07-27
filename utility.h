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

// PROGMEM && PSTR

// Copy a global progmem string to a local char array
#define P_STRCPY(TO, FROM) \
    { \
        unsigned int __s = sizeof(FROM); \
        P_STRNCPY(TO, FROM, __s); \
    }

// Copy the frist N charactor of a global progmem string to a local char array
#define P_STRNCPY(TO, FROM, N) \
    { \
        const char* __p = FROM; \
        for (int __i = 0; __i < N; ++__i) \
        { \
            TO[__i] = pgm_read_byte(__p++); \
        } \
        TO[N - 1] = '\0'; \
    }

// Define a global progmem string
#define P_STR(NAME, STRING) \
    const char NAME[] PROGMEM = STRING;

// Fill data into the global progmem string buffer
#define MAX_CONST_STR_SIZE 60
extern char p_buf[];
#define MIN(A, B)  (A < B ? A : B)
#define P_BUF(STRING) \
    P_STRNCPY(p_buf, PSTR(STRING), MIN(sizeof(STRING), MAX_CONST_STR_SIZE))

// Print log to serial port, use flash to store string
#if DEBUG
#define debugPLog(STRING)   P_BUF(STRING) debugLog(p_buf)
#define debugPPrint(STRING) P_BUF(STRING) debugPrint(p_buf)
#else
#define debugPLog(STRING)
#define debugPPrint(STRING)
#endif
   
// Copy a const string to local char array, use flash to store string
#define strpcpy(TO, FROM) \
    P_STRNCPY(TO, PSTR(FROM), MIN(sizeof(TO), sizeof(FROM)))
#define strpncpy(TO, FROM, N) \
    P_STRNCPY(TO, PSTR(FROM), N)

#endif

