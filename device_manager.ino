#include "device_manager.h"

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

IDisplayDevice* DeviceManager::getDisplayDevice() {
    return m_displayDevice;
}
void DeviceManager::setDisplayDevice(IDisplayDevice* device) {
    m_displayDevice = device;
}

IKeyboardDevice* DeviceManager::getKeyboardDevice() {
    return m_keyboardDevice;
}
void DeviceManager::setKeyboardDevice(IKeyboardDevice* device) {
    m_keyboardDevice = device;
}

INetworkDevice* DeviceManager::getNetworkDevice() {
    return m_networkDevice;
}
void DeviceManager::setNetworkDevice(INetworkDevice* device) {
    m_networkDevice = device;
}

ITimerDevice* DeviceManager::getTimerDevice() {
    return m_timerDevice;
}
void DeviceManager::setTimerDevice(ITimerDevice* device) {
    m_timerDevice = device;
}

