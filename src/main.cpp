#include "Arduino.h"
#include "HID-Project.h"
#include "JoystickMouseSubroutine.h"
#include "VolumeEncoderSubroutine.h"


// Constants are defined in platformio.ini build_flags.
JoystickMouseSubroutine joystickMouseSubroutine(HORZPIN, VERTPIN, SELPIN, INVERT, SENSITIVITY);
VolumeEncoderSubroutine volumeEncoderSubroutine(INPUTCLK, INPUTDT, INPUTSW);
void setup() {
  joystickMouseSubroutine.init();
  volumeEncoderSubroutine.init();
}

void loop() {
  joystickMouseSubroutine.run();
  volumeEncoderSubroutine.run();
}
