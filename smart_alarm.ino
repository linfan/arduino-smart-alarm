#include "http.h"
#include "serial_and_led.h"
#include "oled.h"
#include "irremote.h"

// Initialization
void setup() {
  // Initialize Bridge for HTTP download
  initHttp();
  // Initialize Serial
  initSerialForDebug();
  // Initialize LED connected to Pin 13
  initLedOnPin13();
  // Initialize OLED screen
  initOledScreen();
  // Initialize IRremote
  initIrRemote();
}

enum STATE{
  S_INIT = 0,
  S_IDLE = 1
};
STATE state = S_INIT;

void doDisplay()
{
//  switch(state) {
//  case S_INIT: break;
//  case S_IDLE: break;
//  }
}

void doHandleInput()
{
}

void loop()
{
  doDisplay();
  doHandleInput();
}
