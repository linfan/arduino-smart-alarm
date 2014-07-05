#ifndef __SMART_ALARM_DEVICE_MANAGER_H__
#define __SMART_ALARM_DEVICE_MANAGER_H__

#include "device.h"

class DeviceManager
{
    DeviceManager();
    IDisplayDevice* m_displayDevice;
    IKeyboardDevice* m_keyboardDevice;
    INetworkDevice* m_networkDevice;
    ITimerDevice* m_timerDevice;
    
public:
    static DeviceManager* Ins() {
        static DeviceManager* instance = new DeviceManager();
        return instance;
    }

    void initAllDevice();

    IDisplayDevice* getDisplayDevice();
    void setDisplayDevice(IDisplayDevice* device);

    IKeyboardDevice* getKeyboardDevice();
    void setKeyboardDevice(IKeyboardDevice* device);

    INetworkDevice* getNetworkDevice();
    void setNetworkDevice(INetworkDevice* device);

    ITimerDevice* getTimerDevice();
    void setTimerDevice(ITimerDevice* device);
};

#endif





















