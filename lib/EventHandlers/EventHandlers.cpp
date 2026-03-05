#include "Arduino.h"
#include "HID-Project.h"
#include "JoystickComponent.h"

void onMouseClickHandler(uint8_t action){
  Mouse.press(action);
}

void onMouseReleaseHandler(uint8_t action){
  Mouse.release(action);
}

void onMouseSensitivityHandler(uint8_t action){
  static byte current = 0;
  static const byte presetCount = sizeof(JoystickComponent::sensitivityPresets)/sizeof(JoystickComponent::sensitivityPresets[0]);

  // Update joystick sensitivity, then advance to the next preset index (wrapping).
  JoystickComponent::setSensitivity(JoystickComponent::sensitivityPresets[current]);
  current = (current + 1) % presetCount;

  // Additional bounce delay
  delay(300);
}


void onToggleHandler(uint8_t action, uint8_t actionState)
{
  if (actionState == HIGH ){
    Mouse.press(action);  // click the button down
  }else{
    Mouse.release(action);
  }
}

void doNothing(uint8_t action){}