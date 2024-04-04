#include "Arduino.h"
#include "Vector.h"
#include "HID-Project.h"
#include "JoystickMouseSubroutine.h"
#include "VolumeEncoderSubroutine.h"
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"

// Constants are defined in platformio.ini build_flags.
MomentarySwitchComponent leftMouseSwitch(LEFTCLICKPIN, LEFTLEDPIN, MOUSE_LEFT);
MomentarySwitchComponent rightMouseSwitch(RIGHTCLICKPIN, RIGHTLEDPIN, MOUSE_RIGHT);
MomentarySwitchComponent middleMouseSwitch(MIDDLECLICKPIN, MIDDLELEDPIN, MOUSE_MIDDLE);


MomentarySwitchComponent switchComponents[] = {leftMouseSwitch, rightMouseSwitch, middleMouseSwitch };
Vector<MomentarySwitchComponent> switchComponentsVector(switchComponents, sizeof(switchComponents));
JoystickMouseSubroutine joystickMouseSubroutine(HORZPIN, VERTPIN, INVERT, SENSITIVITY, switchComponentsVector);

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
