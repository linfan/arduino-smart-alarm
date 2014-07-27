#ifndef __SMART_ALARM_NOTIFICATION_H__
#define __SMART_ALARM_NOTIFICATION_H__

enum NotificationType
{
    NOTI_ERROR,
    NOTI_INIT_BEGIN,
    NOTI_INIT_SCREEN_FINISH,
    NOTI_INIT_FINISH,
    NOTI_EVENT_UPDATE,
    NOTI_WAIT,
    NOTI_EVENT_COMMING,
    NOTI_SHOW_NEXT_EVENT,
    NOTI_SKIP_EVENT
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

