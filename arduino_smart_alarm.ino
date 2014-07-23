#include "device_manager.h"
#include "state_switcher.h"
#include "oled_device.h"
#include "timer_one_device.h"
#include "wifi_device.h"
#include "irremote_device.h"
#include "utility.h"
#include "init_state.h"
#include "config.h"

// Initialization
void setup()
{
    initSerialForDebug();
    DeviceManager::Ins()->addDevice(new OledDevice);
    //DeviceManager::Ins()->addDevice(new IrremoteDevice);
    //DeviceManager::Ins()->addDevice(new WifiDevice);
    //DeviceManager::Ins()->addDevice(new TimerOneDevice);
    DeviceManager::Ins()->initAllDevice();
    //StateSwitcher::Ins()->switchTo(new InitState);
    //debugLog("=============== Init done ==============");
}

void loop()
{
    //IState* state = StateSwitcher::Ins()->getCurState();
    //IDisplayDevice* display = DeviceManager::Ins()->getDisplayDevice();
    //display->show(state);
    //state->process();
    //StateSwitcher::Ins()->switchTo(state->nextState());
    DeviceManager::Ins()->process();
    delay(150);
}

