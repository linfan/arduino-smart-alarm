#ifndef __SMART_ALARM_IRREMOTE_DEVICE_H__
#define __SMART_ALARM_IRREMOTE_DEVICE_H__

#include "device.h"
#include "config.h"

class IrremoteDevice : public IKeyboardDevice
{
public:
    void init();
    char translateIR();
    char getChar();
};

#endif



























