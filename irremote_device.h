#ifndef __SMART_ALARM_IRREMOTE_DEVICE_H__
#define __SMART_ALARM_IRREMOTE_DEVICE_H__

#include "device.h"

// Arduino digital pin connected to IR receiver
#define RECEIVER_PIN 8

class IrremoteDevice : public IKeyboardDevice
{
public:
    IrremoteDevice();
    ~IrremoteDevice();
    
    void init();
    char translateIR();
    char getChar();
};

#endif

