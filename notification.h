#ifndef __SMART_ALARM_NOTIFICATION_H__
#define __SMART_ALARM_NOTIFICATION_H__

enum NotificationType
{
    IDLE_WAIT,
    ERROR,
    INIT_BEING,
    INIT_SCREEN_FINISH,
    INIT_FINISH,
    WAIT_FOR_EVENT,
    EVENT_COMMING
};

class Notification
{
public:
    NotificationType type;
    const void* data;
    Notification(NotificationType t, const void* d)
        : type(t), data(d) {}
    ~Notification() {}
};

#endif

