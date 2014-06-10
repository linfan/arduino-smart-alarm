#include "http.h"
#include "serial_and_led.h"
#include "oled.h"
#include "irremote.h"
#include "state_machine.h"

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

void doDisplay()
{
  switch(State::get()) {
  case S_INIT: draw(input); break;
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
