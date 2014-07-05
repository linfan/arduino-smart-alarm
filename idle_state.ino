#include <U8glib.h>
#include "idle_state.h"
#include "device_manager.h"
#include "device.h"
#include "utility.h"

void IdleState::draw(DRAW_HANDLER* u8g)
{
}

void IdleState::process()
{
    //INetworkDevice* d_network = DeviceManager::Ins()->getNetworkDevice();
    //char* buf = d_network->httpGet("event/list?user=1");
}

IState* IdleState::nextState()
{
    return this;
}

















