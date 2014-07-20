#ifndef __SMART_ALARM_NOTIFICATION_DEVICE_H__
#define __SMART_ALARM_NOTIFICATION_DEVICE_H__

#include "event.h"

class INotificationDevice : public IDevice
{
public:
    virtual void notify(Event*) = 0;
};

#endif

