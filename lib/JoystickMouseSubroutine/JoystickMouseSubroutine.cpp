/* HID Joystick Mouse Example
   by: Jim Lindblom
   date: 1/12/2012
   license: MIT License - Feel free to use this code for any purpose.
   No restrictions. Just keep this license if you go on to use this
   code in your future endeavors! Reuse and share.

   This is very simplistic code that allows you to turn the
   SparkFun Thumb Joystick (http://www.sparkfun.com/products/9032)
   into an HID Mouse. The select button on the joystick is set up
   as the mouse left click.
*/
#include "Arduino.h"
#include "HID-Project.h"
#include "Vector.h"
#include "JoystickMouseSubroutine.h"

JoystickMouseSubroutine::JoystickMouseSubroutine(uint8_t horzPin, uint8_t vertPin, int invertMouse, int sensitivity, Vector<MomentarySwitchComponent> switchComponents ){
    _horzPin = horzPin;
    _vertPin = vertPin;
    _invertMouse = invertMouse;
    _sensitivity = sensitivity;
    _switchComponents = switchComponents;
    _numSwitches = sizeof(_switchComponents);
}

void JoystickMouseSubroutine::init()
{
  for (byte i = 0; i < _numSwitches; i++){
    _switchComponents[i].init();
  }

  pinMode(_horzPin, INPUT);  // Set both analog pins as inputs
  pinMode(_vertPin, INPUT);

  delay(1000);  // short delay to let outputs settle
  _vertZero = analogRead(_vertPin);  // get the initial values
  _horzZero = analogRead(_horzPin);  // Joystick should be in neutral position when reading these

  Mouse.begin(); //Init mouse emulation
}

void JoystickMouseSubroutine::run()
{
  _vertValue = analogRead(_vertPin) - _vertZero;  // read vertical offset
  _horzValue = analogRead(_horzPin) - _horzZero;  // read horizontal offset

  if (_vertValue != 0)
    Mouse.move(0, (_invertMouse * (_vertValue / _sensitivity)), 0); // move mouse on y axis
  if (_horzValue != 0)
    Mouse.move((-_invertMouse * (_horzValue / _sensitivity)), 0, 0); // move mouse on x axis


  for (byte i = 0; i < _numSwitches; i++){
    _switchComponents[i].handler();
  }

}
