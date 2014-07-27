#include <string.h>
#include <SoftwareSerial.h>
#include "wifi_device.h"
#include "json_parser.h"
#include "utility.h"

SoftwareSerial wifiSerial(2, 3); // RX, TX

WifiDevice::WifiDevice()
    : m_nextEvent(new Event),
      m_wifiState(WIFI_IDLE),
      m_lastUpdateEventTime(0UL)
{}

void WifiDevice::init()
{
    wifiSerial.begin(4800);
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

#define wifiSent(data)     wifiSerial.print(data)
#define wifiSentLn(data)   wifiSerial.println(data)
#define wifiPmSent(data)   P_BUF(data) wifiSerial.print(p_buf)
#define wifiPmSentLn(data) P_BUF(data) wifiSerial.println(p_buf)

char* WifiDevice::httpGet(char* url)
{
     wifiPmSent("GET ");
     wifiSent(url);
     wifiPmSentLn(" HTTP/1.0");
     wifiPmSentLn("");
     wifiPmSentLn("Connection: close");
     wifiSentLn();
     char header_buf[15] = {'\0'}; // sizeof("\"status\": \"OK\"") + 1
     bool state_ok = false;
     bool too_much_data = false;
     int index = 0;
     int skip_space = 0;
    // It'll spend ~3 seconds to get all data
//    debugPLog("==== HEAD >>");
    for(int i = 0 ; i <= 500; ++i) {
        delay(10);
        if (too_much_data) {
            debugPLog("\nToo much data 0_0!");
            break;
        }
        while (wifiSerial.available()) {
            if (index >= HTTP_BUFFER_SIZE - 2) { // Don't overflow
                too_much_data = true;
                break;
            } else if (state_ok) {
                char c = wifiSerial.read();
                if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
                    c = ' ';
                    skip_space++;
                }
                else
                    skip_space = 0;
                if (skip_space <= 1) { // Skip continuing space
                    m_buf[index++] = c;
                    m_buf[index] = '\0';
                }
            } else {
                // remove header
                for (int j = 0; j < 13; ++j) {
                    header_buf[j] = header_buf[j+1];
                }
                header_buf[13] = wifiSerial.read();
                header_buf[14] = '\0';
                //debugPrint(header_buf[13]);
                if (strcmp(header_buf, "\"status\": \"OK\"") == 0)
                {
                    //debugPLog("\n==== << HEAD\nGet OK state ^^!");
                    state_ok = true;
                }
            }
        }
    }
    m_buf[index] = '\0';
    if (!state_ok) {
        debugPLog("Cannot get OK state : (");
        return "";
    }
    debugPLog("==== BODY >>");
    debugLog(m_buf);
    debugPLog("==== << BODY");
    return m_buf;
}

void WifiDevice::getNetworkTime(char* timeStr)
{
#if WIFI_DEBUG
    strpncpy(timeStr, "2014-07-04T16:00:00+08:00", 26);
#else
    char* json = httpGet("/time");
    JsonParser::Ins()->extractValue(json, "time", timeStr);
#endif
}

void WifiDevice::getNthEvent(int index, Event* event)
{
#if WIFI_DEBUG
    strpcpy(event->summary, "Reminder: Submit your timesheet (Suncorp Clarity and TW)");
    strpcpy(event->startTime, "2014-07-04T16:00:00+08:00");
    strpcpy(event->endTime, "2014-07-04T16:15:00+08:00");
    strpcpy(event->organizer, "Qi Wen");
    strpcpy(event->location, "N/A");
#else
    debugPLog("Geting event ..");
    //char* json = httpGet("/event/list?user=1");
    //delay(2000);
    char* json = httpGet("/event/list?user=1&lazy=1");
    JsonParser::Ins()->extractValue(json, "summary", event->summary);
    JsonParser::Ins()->extractValue(json, "start", event->startTime);
    JsonParser::Ins()->extractValue(json, "end", event->endTime);
    JsonParser::Ins()->extractValue(json, "organizer", event->organizer);
    JsonParser::Ins()->extractValue(json, "location", event->location);
#endif
}

P_STR(INTERNET_ERR, "Cannot connect to internet !")

void WifiDevice::initLocalTime()
{
    static int retry_times = 0;
    char strTime[26];
//    debugPLog("Begin get time");
    getNetworkTime(strTime);
    debugPPrint(">> Init time: ");
    debugPrint(strTime);
    debugPPrint(" [");
    debugPrint(strlen(strTime));
    debugPLog("]");

    if (strlen(strTime) == 0)
    {
        retry_times++;
        if (retry_times < 3) {
            debugPLog("Get time failed, retry..");
            delay(500);
        }
        else {
            DeviceManager::Ins()->notify(new Notification(NOTI_ERROR, INTERNET_ERR));
        }
    }
    else
    {
        retry_times = 0;
        debugPLog("Set clock..");
        Clock::Ins()->setTime(Clock::ToNumericTime(strTime));
        DeviceManager::Ins()->notify(new Notification(NOTI_INIT_FINISH, NULL));
    }
}

void WifiDevice::updateEvent()
{
    static int retry_times = 0;
//    char startTime[26];
    debugPLog("Begin update event..");
//    strcpy(startTime, m_nextEvent->startTime);
    getNthEvent(0, m_nextEvent);
    if (strcmp("", m_nextEvent->startTime) == 0)
    {
        retry_times++;
        if (retry_times < 3) {
            debugPLog("Get event failed, retry..");
            delay(500);
        }
        else {
            DeviceManager::Ins()->notify(new Notification(NOTI_ERROR, INTERNET_ERR));
        }
    }
    else //if (strcmp(startTime, m_nextEvent->startTime) != 0)
    {
        retry_times = 0;
        debugPrint(">> Event summary: ");
        debugLog(m_nextEvent->summary);
        DeviceManager::Ins()->notify(new Notification(NOTI_SHOW_NEXT_EVENT, m_nextEvent));
    }
}

void WifiDevice::checkEvent()
{
    unsigned long curTime = Clock::Ins()->getTime();
    if (m_lastUpdateEventTime == 0UL) {
        m_lastUpdateEventTime = curTime;
    } else if (curTime - m_lastUpdateEventTime > UPDATE_INTERVAL) {
        m_lastUpdateEventTime = curTime;
        DeviceManager::Ins()->notify(new Notification(NOTI_EVENT_UPDATE, NULL));
    }
    unsigned long nextEventTime = Clock::Ins()->ToNumericTime(m_nextEvent->startTime);
    if (nextEventTime - curTime < NOTIFY_HEAD_TIME)
    {
        DeviceManager::Ins()->notify(new Notification(NOTI_EVENT_COMMING, m_nextEvent));
    }
}

void waitEventFinish()
{
    unsigned long curTime = Clock::Ins()->getTime();
    unsigned long nextEventTime = Clock::Ins()->ToNumericTime(m_nextEvent->startTime);
    // Do not update m_nextEvent in this state
    if (nextEventTime - curTime < 0)
    {
        DeviceManager::Ins()->notify(new Notification(NOTI_EVENT_UPDATE, NULL));   
    }
}

void WifiDevice::step()
{
    switch (m_wifiState)
    {
    case WIFI_IDLE:
        break;
    case WIFI_INIT_TIME:
        initLocalTime();
        break;
    case WIFI_FETCH_EVENT:
        updateEvent();
        break;
    case WIFI_WAITING:
        checkEvent();
        break;
    case WIFI_WAIT_EVENT_FINISH:
        waitEventFinish();
        break;
    }
}

void WifiDevice::notify(Notification* noti)
{
    switch(noti->type)
    {
    case NOTI_INIT_SCREEN_FINISH:
        m_wifiState = WIFI_INIT_TIME;
        break;
    case NOTI_INIT_FINISH:
        m_wifiState = WIFI_FETCH_EVENT;
        break;
    case NOTI_WAIT:
        m_wifiState = WIFI_WAITING;
        break;
    case NOTI_EVENT_UPDATE:
        m_wifiState = WIFI_FETCH_EVENT;
        break;
    case NOTI_ERROR:
        m_wifiState = WIFI_IDLE;
        break;
    case NOTI_EVENT_COMMING:
        m_wifiState = WIFI_WAIT_EVENT_FINISH;
        break;
    }
}

