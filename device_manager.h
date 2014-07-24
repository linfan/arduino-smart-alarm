#ifndef __SMART_ALARM_DEVICE_MANAGER_H__
#define __SMART_ALARM_DEVICE_MANAGER_H__

#include "device.h"
#include "device_list.h"
#include "notification.h"

class DeviceManager
{
    DeviceManager();
    //IDisplayDevice* m_displayDevice;
    //IKeyboardDevice* m_keyboardDevice;
    //INetworkDevice* m_networkDevice;
    //ITimerDevice* m_timerDevice;

    void exec_notification();
    DeviceList m_deviceList;
    DeviceList m_notificationDeviceList;

public:
    static DeviceManager* Ins() {
        static DeviceManager* instance = new DeviceManager();
        return instance;
    }

    void initAllDevice();
    void addDevice(IDevice* device);
    void notify(Notification* noti);
    void process();

    //IDisplayDevice* getDisplayDevice();
    //IKeyboardDevice* getKeyboardDevice();
    //INetworkDevice* getNetworkDevice();
    //ITimerDevice* getTimerDevice();
};

#endif

