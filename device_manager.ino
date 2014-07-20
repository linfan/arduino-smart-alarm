#include "device_manager.h"
#include "event.h"

DeviceManager::DeviceManager()
{
    m_displayDevice = NULL;
    m_keyboardDevice = NULL;
    m_networkDevice = NULL;
    m_timerDevice = NULL;
}

void DeviceManager::initAllDevice()
{
    if(m_displayDevice) m_displayDevice->init();
    if(m_keyboardDevice) m_keyboardDevice->init();
    if(m_networkDevice) m_networkDevice->init();
    if(m_timerDevice) m_timerDevice->init();
}

void DeviceManager::notify(Event* event)
{
    DeviceNode* node = m_notificationDeviceList.head();
    while(node) {
        INotificationDevice* notifyNode = (INotificationDevice*)(node->device());
        notifyNode->notify(event);
        node = node->next();
    }
}

void DeviceManager::addDevice(IDevice* device)
{
    if ((INotificationDevice*)device)
        m_notificationDeviceList.add(new DeviceNode(device));
    if ((IDisplayDevice*)device)
        m_displayDevice = (IDisplayDevice*)device;
    else if ((IKeyboardDevice*)device)
        m_keyboardDevice = (IKeyboardDevice*)device;
    else if ((INetworkDevice*)device)
        m_networkDevice = (INetworkDevice*)device;
    else if ((ITimerDevice*)device)
        m_timerDevice = (ITimerDevice*)device;
    m_deviceList.add(new DeviceNode(device));
}

IDisplayDevice* DeviceManager::getDisplayDevice() {
    return m_displayDevice;
}

IKeyboardDevice* DeviceManager::getKeyboardDevice() {
    return m_keyboardDevice;
}

INetworkDevice* DeviceManager::getNetworkDevice() {
    return m_networkDevice;
}

ITimerDevice* DeviceManager::getTimerDevice() {
    return m_timerDevice;
}

