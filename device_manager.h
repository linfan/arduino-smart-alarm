#ifndef __SMART_ALARM_DEVICE_MANAGER_H__
#define __SMART_ALARM_DEVICE_MANAGER_H__

#include "device.h"
#include "device_list.h"
#include "notification.h"

class DeviceManager
{
private:
    DeviceManager();
    DeviceList m_deviceList;
    
public:
    static DeviceManager* Ins() {
        static DeviceManager* instance = new DeviceManager();
        return instance;
    }

    void initAllDevice();
    void addDevice(IDevice* device);
    void notify(Notification* noti);
    void process();
};

#endif

