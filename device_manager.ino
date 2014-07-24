#include "device_manager.h"
#include "event.h"

DeviceManager::DeviceManager()
{
    //m_displayDevice = NULL;
    //m_keyboardDevice = NULL;
    //m_networkDevice = NULL;
    //m_timerDevice = NULL;
}

void DeviceManager::exec_notification()
{

}

void DeviceManager::initAllDevice()
{
    exec_notification();
    DeviceNode* node = m_deviceList.head();
    while(node) {
        IDevice* notifyNode = node->device();
        notifyNode->init();
        node = node->next();
    }
}

void DeviceManager::process()
{
    DeviceNode* node = m_deviceList.head();
    while(node) {
        IDevice* notifyNode = node->device();
        notifyNode->step();
        node = node->next();
    }
}

void DeviceManager::notify(Notification* noti)
{
    DeviceNode* node = m_notificationDeviceList.head();
    while(node) {
        INotificationDevice* notifyNode = (INotificationDevice*)(node->device());
        notifyNode->notify(noti);
        node = node->next();
    }
    delete noti;
}

void DeviceManager::addDevice(IDevice* device)
{
    if ((INotificationDevice*)device)
        m_notificationDeviceList.add(new DeviceNode(device));
    //if ((IDisplayDevice*)device)
    //    m_displayDevice = (IDisplayDevice*)device;
    //else if ((IKeyboardDevice*)device)
    //    m_keyboardDevice = (IKeyboardDevice*)device;
    //else if ((INetworkDevice*)device)
    //    m_networkDevice = (INetworkDevice*)device;
    //else if ((ITimerDevice*)device)
    //    m_timerDevice = (ITimerDevice*)device;
    m_deviceList.add(new DeviceNode(device));
}

//IDisplayDevice* DeviceManager::getDisplayDevice() {
//    return m_displayDevice;
//}
//
//IKeyboardDevice* DeviceManager::getKeyboardDevice() {
//    return m_keyboardDevice;
//}
//
//INetworkDevice* DeviceManager::getNetworkDevice() {
//    return m_networkDevice;
//}
//
//ITimerDevice* DeviceManager::getTimerDevice() {
//    return m_timerDevice;
//}

