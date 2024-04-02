#include "Arduino.h"
#include "HID-Project.h"
#include "JoystickMouseSubroutine.h"
#include "VolumeEncoderSubroutine.h"


// Constants are defined in platformio.ini build_flags.
JoystickMouseSubroutine joystickMouseSubroutine(HORZPIN, VERTPIN, INVERT, SENSITIVITY, LEFTCLICKPIN, RIGHTCLICKPIN, MIDDLECLICKPIN, LEFTLEDPIN, RIGHTLEDPIN, MIDDLELEDPIN);
//VolumeEncoderSubroutine volumeEncoderSubroutine(INPUTCLK, INPUTDT, INPUTSW);

// Initialize components.
void setup() {
  joystickMouseSubroutine.init();
  //volumeEncoderSubroutine.init();
}

// Run component Subroutine.
void loop() {
  joystickMouseSubroutine.run();
  //volumeEncoderSubroutine.run();
}
