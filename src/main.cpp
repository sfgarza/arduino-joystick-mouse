#include "Arduino.h"
#include "Vector.h"
#include "HID-Project.h"
#include "JoystickMouseSubroutine.h"
#include "VolumeEncoderSubroutine.h"
#include "JoystickComponent.h"
#include "MomentarySwitchComponent.h"
#include "EventHandlers.h"

// Constants are defined in platformio.ini build_flags.
JoystickComponent joystickComponent(HORZPIN, VERTPIN, INVERTX, INVERTY);

// Event handler Functions defined in EventHandlers.cpp
MomentarySwitchComponent leftMouseSwitch(LEFTCLICKPIN, LEFTLEDPIN, MOUSE_LEFT, &onMouseClickHandler, &onMouseReleaseHandler);
MomentarySwitchComponent rightMouseSwitch(RIGHTCLICKPIN, RIGHTLEDPIN, MOUSE_RIGHT, &onMouseClickHandler, &onMouseReleaseHandler);
//MomentarySwitchComponent middleMouseSwitch(MIDDLECLICKPIN, MIDDLELEDPIN, MOUSE_MIDDLE,  &onMouseClickHandler, &onMouseReleaseHandler);
MomentarySwitchComponent middleMouseSwitch(MIDDLECLICKPIN, MIDDLELEDPIN, MOUSE_MIDDLE,  &onMouseSensitivityHandler, &doNothing);

MomentarySwitchComponent switchComponents[] = {leftMouseSwitch, rightMouseSwitch, middleMouseSwitch };
Vector<MomentarySwitchComponent> switchComponentsVector(switchComponents, sizeof(switchComponents));
JoystickMouseSubroutine joystickMouseSubroutine(joystickComponent, switchComponentsVector);

// Initialize components.
void setup() {
  joystickMouseSubroutine.init();
}

// Run component Subroutine.
void loop() {
  joystickMouseSubroutine.run();
}
