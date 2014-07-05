#include <string.h>
#include "wifi_device.h"

void WifiDevice::init()
{
}

// HTTP/1.0 200 OK \n
// Date: Thu, 03 Jul 2014 16:39:57 GMT \n
// Server: WSGIServer/0.1 Python/2.7.6 \n
// Content-Length: 1010 \n
// Content-Type: application/json \n
// Cache-Control: no-cache \n
//  \n

// {"status": "OK", "events": [{"start": "2014-07-04T16:00:00+08:00", "organizer": "Qi Wen", "end": "2014-07-04T16:15:00+08:00", "location": "N/A", "summary": "Reminder: Submit your timesheet (Suncorp Clarity and TW)"}, {"start": "2014-07-07T16:30:00+08:00", "organizer": "Lanying Wu", "end": "2014-07-07T17:30:00+08:00", "location": "Ping Pang Room", "summary": "AWS training (2) - workshop"}]}

// {"status": "OK", "time": "2014-07-04T16:00:00+08:00"}

char* WifiDevice::getNetworkTime()
{
    return "2014-07-04T16:00:00+08:00";
}

Event* WifiDevice::getNthEvent(int index)
{
    char* eventStr = "{\"start\": \"2014-07-04T16:00:00+08:00\", \"organizer\": \"Qi Wen\", \"end\": \"2014-07-04T16:15:00+08:00\", \"location\": \"N/A\", \"summary\": \"Reminder: Submit your timesheet (Suncorp Clarity and TW)\"}";
    return 0;
}























