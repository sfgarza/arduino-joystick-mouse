#include "Mouse.h"
#include "JoystickMouseSubroutine.h"

byte horzPin = A0;  // Analog output of horizontal joystick pin
byte vertPin = A1;  // Analog output of vertical joystick pin
byte selPin = 9;  // select button pin of joystick
int invertMouse = -1;         //Noninverted joystick based on orientation

JoystickMouseSubroutine joystickMouseSubroutine( horzPin,  vertPin,  selPin, invertMouse);

void setup() {
  joystickMouseSubroutine.init();
}

void loop() {
  joystickMouseSubroutine.run();
}
