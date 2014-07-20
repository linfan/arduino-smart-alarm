#ifndef __SMART_ALARM_NOTIFICATION_DEVICE_H__
#define __SMART_ALARM_NOTIFICATION_DEVICE_H__

class INotificationDevice : public IDevice
{
    void notify() = 0;
};

#endif