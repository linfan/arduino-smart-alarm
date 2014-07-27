#include "device_manager.h"
#include "oled_device.h"
#include "timer_one_device.h"
#include "wifi_device.h"
#include "irremote_device.h"
#include "utility.h"
#include "config.h"

// Initialization
void setup()
{
    initSerialForDebug();
    DeviceManager::Ins()->addDevice(new OledDevice);
    DeviceManager::Ins()->addDevice(new IrremoteDevice);
    DeviceManager::Ins()->addDevice(new WifiDevice);
    DeviceManager::Ins()->addDevice(new TimerOneDevice);
    DeviceManager::Ins()->initAllDevice();
    debugPLog("=============== Init done ==============");
}

void loop()
{
    DeviceManager::Ins()->process();
    delay(150);
}

