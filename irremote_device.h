#ifndef __SMART_ALARM_IRREMOTE_DEVICE_H__
#define __SMART_ALARM_IRREMOTE_DEVICE_H__

#include "device.h"
#include "config.h"

enum IrState
{
    IR_IDLE,
    IR_ERROR_HANDLE,
    IR_WAITING,
    IR_EVENT_COMMING
};

class IrremoteDevice : public IDevice
{
private:
    IrState m_irState;
    void waitForReset();
    void waitForEvent();
    void waitForRespond();
public:
    IrremoteDevice() : m_irState(IR_IDLE) {}
    void init();
    void step();
    void notify(Notification*);
    char translateIR();
    char getChar();
};

#endif

