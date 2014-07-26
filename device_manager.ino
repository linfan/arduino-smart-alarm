#include "device_manager.h"
#include "event.h"
#include "notification.h"
#include "utility.h"

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
    debugLog(NOTI_INIT_BEGIN);
    notify(new Notification(NOTI_INIT_BEGIN, NULL));
}

void DeviceManager::process()
{
    FOREACH_DEVICE(
        device->step();
    )
}

void DeviceManager::notify(Notification* noti)
{
    debugPrint(">> Sent notification ");
    debugLog((int)(noti->type));
    FOREACH_DEVICE(
        device->notify(noti);
    )
}

void DeviceManager::addDevice(IDevice* device)
{
    m_deviceList.add(new DeviceNode(device));
}

