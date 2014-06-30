#include "device_manager.h"

void DeviceManager::initAllDevice()
{
    if(m_displayDevice) m_displayDevice->init();
    if(m_keyboardDevice) m_keyboardDevice->init();
    if(m_networkDevice) m_networkDevice->init();
    if(m_timerDevice) m_timerDevice->init();
    if(m_realTimeDevice) m_realTimeDevice->init();
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

IRealTimeDevice* DeviceManager::getRealTimeDevice() {
    return m_realTimeDevice;
}
void DeviceManager::setRealTimeDevice(IRealTimeDevice* device) {
    m_realTimeDevice = device;
}









