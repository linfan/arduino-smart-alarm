#ifndef __SMART_ALARM_EVENT_H__
#define __SMART_ALARM_EVENT_H__

struct Event
{
    char summary[55];   // better to be 60
    char startTime[6];  // better to be 26
    char endTime[6];    // better to be 26
    char location[15];  // better to be 20
    char organizer[15]; // better to be 20
};

#endif






















