#ifndef __SMART_ALARM_NOTIFICATION_H__
#define __SMART_ALARM_NOTIFICATION_H__

enum NotificationType
{
    INIT_BEING,
    INIT_SCREEN_FINISH,
    INIT_FINISH,
    NEW_EVENT
};

class Notification
{
public:
    NotificationType type;
    void* data;
    Notification(NotificationType t, void* d)
        : type(t), data(d) {}
    ~Notification() {}
};

#endif

