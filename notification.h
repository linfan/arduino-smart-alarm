#ifndef __SMART_ALARM_NOTIFICATION_H__
#define __SMART_ALARM_NOTIFICATION_H__

enum NotificationType
{
    NOTI_IDLE_WAIT           = 0,
    NOTI_ERROR               = 1,
    NOTI_INIT_BEGIN          = 2,
    NOTI_INIT_SCREEN_FINISH  = 3,
    NOTI_INIT_FINISH         = 4,
    NOTI_EVENT_CHANGE        = 5,
    NOTI_EVENT_COMMING       = 6
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

