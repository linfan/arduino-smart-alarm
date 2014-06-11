#include "http.h"
#include "serial_and_led.h"
#include "oled.h"
#include "irremote.h"
#include "state_machine.h"
#include "timer.h"

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
  // Initialize Timer
  initInternalTimer();
}

void doDisplay()
{
  switch(State::get()) {
  case S_INIT: break;
  case S_IDLE: break;
  }
}

void doHandleInput()
{
}

void loop()
{
  doDisplay();
  doHandleInput();
}
