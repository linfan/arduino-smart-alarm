#ifndef __SMART_ALARM_DEVICE_MANAGER_H__
#define __SMART_ALARM_DEVICE_MANAGER_H__

#include "device.h"
#include "notification_device.h"
#include "device_list.h"

class DeviceManager
{
    DeviceManager();
    IDisplayDevice* m_displayDevice;
    IKeyboardDevice* m_keyboardDevice;
    INetworkDevice* m_networkDevice;
    ITimerDevice* m_timerDevice;

    DeviceList m_deviceList;
    DeviceList m_notificationDeviceList;

public:
    static DeviceManager* Ins() {
        static DeviceManager* instance = new DeviceManager();
        return instance;
    }

    void initAllDevice();
    void addDevice(IDevice* device);
    void notify(Event* event);

    IDisplayDevice* getDisplayDevice();
    IKeyboardDevice* getKeyboardDevice();
    INetworkDevice* getNetworkDevice();
    ITimerDevice* getTimerDevice();
};

#endif

