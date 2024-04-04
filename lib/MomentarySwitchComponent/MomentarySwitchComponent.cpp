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
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"


void MomentarySwitchComponent::init()
{
  MomentarySwitchInterface::init();
}

void MomentarySwitchComponent::momentaryPresshandler(void (*onClickCallback)(byte), void (*onReleaseCallback)(byte))
{
  if ((digitalRead(_clickPin) == 0) && (!_clickFlag)) // if the button is pressed
  {
    _clickFlag = 1;
    if (_hasLED)
    {
      digitalWrite(_ledPin, HIGH);
    }
    onClickCallback(_switchAction);
    delay(100);
  }
  else if ((digitalRead(_clickPin)) && (_clickFlag)) // if the  button is not pressed
  {
    _clickFlag = 0;
    if (_hasLED)
    {
      digitalWrite(_ledPin, LOW);
    }
    onReleaseCallback(_switchAction);
  }
}

void MomentarySwitchComponent::togglePresshandler(void (*onToggleCallback)(byte, byte ))
{
  _lastState = _currentState;           // save the last state
  _currentState = digitalRead(_clickPin); // read new state

  if (_lastState == HIGH && _currentState == LOW)
  {

    // toggle state of LED
    _actionState = !_actionState;

    if (_hasLED)
    {
      // control LED arccoding to the toggled state
      digitalWrite(_ledPin, _actionState);
    }
    onToggleCallback(_switchAction, _actionState);
    delay(50);
  }
}