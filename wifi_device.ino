#include <string.h>
#include <SoftwareSerial.h>
#include "wifi_device.h"
#include "json_parser.h"

SoftwareSerial wifiSerial(2, 3); // RX, TX

void WifiDevice::init()
{
    wifiSerial.begin(4800);
}

void WifiDevice::step()
{
    
}

// HTTP/1.0 200 OK \n
// Date: Thu, 03 Jul 2014 16:39:57 GMT \n
// Server: WSGIServer/0.1 Python/2.7.6 \n
// Content-Length: 1010 \n
// Content-Type: application/json \n
// Cache-Control: no-cache \n
//  \n

// {"status": "OK", "events": [{"start": "2014-07-07T16:30:00+08:00", "organizer": "Lanying Wu", "end": "2014-07-07T17:30:00+08:00", "location": "Ping Pang Room", "summary": "AWS training (2) - workshop"}]}

// {"status": "OK", "time": "2014-07-04T16:00:00+08:00"}

char* WifiDevice::httpGet(char* url)
{
     wifiSerial.print("GET ");
     wifiSerial.print(url);
     wifiSerial.println(" HTTP/1.1");
     wifiSerial.println("");
     wifiSerial.println("Connection: close");
     wifiSerial.println("Host: the-1.net:9999");
     wifiSerial.println();
     char header_buf[15] = {'\0'}; // sizeof("\"status\": \"OK\"") + 1
     bool state_ok = false;
     int index = 0;
    // It'll spend 1 min to get all data
    for(int i = 0 ; i = 10; ++i) {
        delay(100);
        while (wifiSerial.available()) {
            if (index >= HTTP_BUFFER_SIZE - 2) // Don't overflow
                break;
            if (state_ok) {
                m_buf[index] = wifiSerial.read();
                ++index;
            } else {
                // remove header
                for (int j = 0; j < 13; ++j) {
                    header_buf[j] = header_buf[j+1];
                }
                header_buf[13] = wifiSerial.read();
                header_buf[14] = '\0';
                if (strcmp(header_buf, "\"status\": \"OK\"") == 0)
                    state_ok = true;
            }
        }
    }
    m_buf[index] = '\0';
    return m_buf;
}

#define WIFI_DEBUG 0

void WifiDevice::getNetworkTime(char* timeStr)
{
    char* json = httpGet("/time");
#if WIFI_DEBUG
    strcpy(timeStr, "2014-07-04T16:00:00+08:00");
#else
    JsonParser::Ins()->extractValue(json, "time", timeStr);
#endif
}

void WifiDevice::getNthEvent(int index, Event* event)
{
    char* json = httpGet("/event/list?user=1");
#if WIFI_DEBUG
    strcpy(event->summary, "Reminder: Submit your timesheet (Suncorp Clarity and TW)");
    strcpy(event->startTime, "2014-07-04T16:00:00+08:00");
    strcpy(event->endTime, "2014-07-04T16:15:00+08:00");
    strcpy(event->organizer, "Qi Wen");
    strcpy(event->location, "N/A");
#else
    JsonParser::Ins()->extractValue(json, "summary", event->summary);
    JsonParser::Ins()->extractValue(json, "start", event->startTime);
    JsonParser::Ins()->extractValue(json, "end", event->endTime);
    JsonParser::Ins()->extractValue(json, "organizer", event->organizer);
    JsonParser::Ins()->extractValue(json, "location", event->location);
#endif
}

void WifiDevice::initLocalTime()
{
    char* strTime = new char[26];
    debugLog("Begin get time");
    getNetworkTime(strTime);

    debugLog(strTime);
    if (strlen(strTime) == 0)
    {
        DeviceManager::Ins()->notify(new Notification(ERROR, "Cannot connect to internet !"));
    }
    else
    {
        Clock::Ins()->setTime(Clock::ToNumericTime(strTime));
        DeviceManager::Ins()->notify(new Notification(INIT_FINISH, NULL));
    }
}

void WifiDevice::notify(Notification* noti)
{
    switch(noti->type)
    {
    case INIT_SCREEN_FINISH:
        initLocalTime();
        break;
    }
}

