#ifndef __SMART_ALARM_IRREMOTE_DEVICE_H__
#define __SMART_ALARM_IRREMOTE_DEVICE_H__

#include "device.h"
#include "config.h"

class IrremoteDevice : public IKeyboardDevice
{
public:
    void init();
    void step();
    char translateIR();
    char getChar();
};

#endif

