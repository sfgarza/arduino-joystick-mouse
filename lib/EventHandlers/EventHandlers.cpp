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
  static byte presetSize = sizeof(JoystickComponent::sensitivityPresets)/sizeof(JoystickComponent::sensitivityPresets[0]) - 1;

  // Reset current index to 0 after iterating through all presets.
  if(current > presetSize){
    current = 0;
  }

  // Update joystick sensitivity, then set current to the next index.
  JoystickComponent::setSensitivity(JoystickComponent::sensitivityPresets[current++]);

  // Addional bounce delay
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