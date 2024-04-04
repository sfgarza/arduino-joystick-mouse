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
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"

MomentarySwitchComponent::MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t mouseAction):MomentarySwitchInterface(clickPin, ledPin)
{
    _clickFlag = 0;
    _mouseAction = mouseAction;
};

MomentarySwitchComponent::MomentarySwitchComponent(uint8_t clickPin, uint8_t mouseAction):MomentarySwitchInterface(clickPin)
{
    _clickFlag = 0;
    _mouseAction = mouseAction;
};

void MomentarySwitchComponent::init()
{
  MomentarySwitchInterface::init();
  Mouse.begin(); //Init mouse emulation
}

void MomentarySwitchComponent::handler()
{
  if ((digitalRead(_clickPin) == 0) && (!_clickFlag))  // if the button is pressed
  {
    _clickFlag = 1;
    if(_hasLED){
      digitalWrite(_ledPin, HIGH);
    }
    Mouse.press(_mouseAction);  // click the button down
  }else if ((digitalRead(_clickPin)) && (_clickFlag)) // if the  button is not pressed
  {
    _clickFlag = 0;
    if(_hasLED){
      digitalWrite(_ledPin, LOW);
    }
    Mouse.release(_mouseAction);  // release the button
  }
}