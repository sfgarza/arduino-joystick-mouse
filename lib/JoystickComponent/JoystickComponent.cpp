#include "Arduino.h"
#include "HID-Project.h"
#include "Vector.h"
#include "JoystickComponent.h"

// Set initial sensitivity to globally defined CURSOR_MEDIUM
int JoystickComponent::_sensitivity = CURSOR_MEDIUM;
const int JoystickComponent::sensitivityPresets[3] = {CURSOR_SLOW, CURSOR_FAST, CURSOR_MEDIUM};

JoystickComponent::JoystickComponent(uint8_t horzPin, uint8_t vertPin, int invertX, int invertY){
    _horzPin = horzPin;
    _vertPin = vertPin;
    _invertX = invertX;
    _invertY = invertY;
}

void JoystickComponent::init()
{
  pinMode(_horzPin, INPUT);  // Set both analog pins as inputs
  pinMode(_vertPin, INPUT);

  delay(1000);  // short delay to let outputs settle
  _vertZero = analogRead(_vertPin);  // get the initial values
  _horzZero = analogRead(_horzPin);  // Joystick should be in neutral position when reading these

  Mouse.begin(); //Init mouse emulation
}

void JoystickComponent::handler()
{
  _vertValue = analogRead(_vertPin) - _vertZero;  // read vertical offset
  _horzValue = analogRead(_horzPin) - _horzZero;  // read horizontal offset

  // Invert and calculate sensitivity
  _vertValue = _invertY * (_vertValue / _sensitivity);
  _horzValue = _invertX * (_horzValue / _sensitivity);

  if (_vertValue != 0 || _horzValue != 0)
    Mouse.move(_horzValue, _vertValue, 0); // move mouse on y axis

}

void JoystickComponent::setSensitivity(int sensitivity)
{
  JoystickComponent::_sensitivity = sensitivity;
}
