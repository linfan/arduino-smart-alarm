#include "irremote_device.h"
#include <IRremote.h>  // IR remote control

int receiver = RECEIVER_PIN;

IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'

void IrremoteDevice::init()
{
    irrecv.enableIRIn(); // Start the receiver
}

void IrremoteDevice::step()
{

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

