#include "Arduino.h"
#include "HID-Project.h"
#include "Vector.h"
#include "JoystickComponent.h"

JoystickComponent::JoystickComponent(uint8_t horzPin, uint8_t vertPin, int invertX, int invertY, int sensitivity ){
    _horzPin = horzPin;
    _vertPin = vertPin;
    _invertX = invertX;
    _invertY = invertY;
    _sensitivity = sensitivity;
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

  if (_vertValue != 0)
    Mouse.move(0, (_invertX * (_vertValue / _sensitivity)), 0); // move mouse on y axis
  if (_horzValue != 0)
    Mouse.move((_invertY * (_horzValue / _sensitivity)), 0, 0); // move mouse on x axis

}
