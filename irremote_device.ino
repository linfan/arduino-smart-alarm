#include <IRremote.h>  // IR remote control
#include "irremote_device.h"
#include "utility.h"

int receiver = RECEIVER_PIN;

IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'

void IrremoteDevice::init()
{
    irrecv.enableIRIn(); // Start the receiver
}

char IrremoteDevice::translateIR()
{
    switch(results.value)   // describing KEYES Remote IR codes 
    {
    case 0xFF629D: return 'U'; break;
    case 0xFF22DD: return 'L'; break;
    case 0xFF02FD: return 'O'; break;
    case 0xFFC23D: return 'R'; break;
    case 0xFFA857: return 'D'; break;
    case 0xFF6897: return '1'; break;
    case 0xFF9867: return '2'; break;
    case 0xFFB04F: return '3'; break;
    case 0xFF30CF: return '4'; break;
    case 0xFF18E7: return '5'; break;
    case 0xFF7A85: return '6'; break;
    case 0xFF10EF: return '7'; break;
    case 0xFF38C7: return '8'; break;
    case 0xFF5AA5: return '9'; break;
    case 0xFF42BD: return '*'; break;
    case 0xFF4AB5: return '0'; break;
    case 0xFF52AD: return '#'; break;
    case 0xFFFFFFFF: return 'R'; break; // Repeat
    default: return '\0';
    }
    //delay(500); // Do not get immediate repeat
}

char IrremoteDevice::getChar()
{
    if (irrecv.decode(&results)) // have we received an IR signal?
    {
        char key = translateIR();
        irrecv.resume();
        return key;
    }
    return '\0';
}

void IrremoteDevice::waitForReset()
{
    switch(getChar())
    {
    case '*':  // Re-initialize system
        DeviceManager::Ins()->notify(new Notification(NOTI_INIT_BEGIN, NULL));
        break;
    }
}

void IrremoteDevice::waitForEvent()
{
    switch(getChar())
    {
    case '*':  // Show next event
        DeviceManager::Ins()->notify(new Notification(NOTI_SHOW_NEXT_EVENT, NULL));
        break;
    case '#':  // Reflush event cache now
        DeviceManager::Ins()->notify(new Notification(NOTI_EVENT_UPDATE, NULL));
        break;
    }
}

void IrremoteDevice::waitForRespond()
{
    switch(getChar())
    {
    case '*':  // Stop reminding current event
        DeviceManager::Ins()->notify(new Notification(NOTI_SKIP_EVENT, NULL));
        break;
    }
}

void IrremoteDevice::step()
{
    switch (m_irState)
    {
    case IR_IDLE:
        break;
    case IR_ERROR_HANDLE:
        waitForReset();
        break;
    case IR_WAITING:
        waitForEvent();
        break;
    case IR_EVENT_COMMING:
        waitForRespond();
        break;
    }
}

void IrremoteDevice::notify(Notification* noti)
{
    switch(noti->type)
    {
    case NOTI_WAIT:
        m_irState = IR_WAITING;
        break;
    case NOTI_EVENT_COMMING:
        m_irState = IR_EVENT_COMMING;
        break;
    case NOTI_ERROR:
        m_irState = IR_ERROR_HANDLE;
        break;
    }
}

