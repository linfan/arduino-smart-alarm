#include "device_manager.h"
#include "event.h"

#define FOREACH_DEVICE(CODE) \
    DeviceNode* node = m_deviceList.head(); \
    while(node) { \
        IDevice* device = node->device(); \
        CODE \
        node = node->next(); \
    }

DeviceManager::DeviceManager()
{
}

void DeviceManager::initAllDevice()
{
    FOREACH_DEVICE(
        device->init();
    )
}

void DeviceManager::process()
{
    FOREACH_DEVICE(
        device->step();
    )
}

void DeviceManager::notify(Notification* noti)
{
    FOREACH_DEVICE(
        device->notify(noti);
    )
}

void DeviceManager::addDevice(IDevice* device)
{
    m_deviceList.add(new DeviceNode(device));
}

