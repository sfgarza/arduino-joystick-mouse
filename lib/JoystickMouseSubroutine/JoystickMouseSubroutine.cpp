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
#include "JoystickComponent.h"

JoystickMouseSubroutine::JoystickMouseSubroutine(JoystickComponent joystickComponent, Vector<MomentarySwitchComponent> switchComponents ) : _joystickComponent{joystickComponent}, _switchComponents{switchComponents}
{
    _joystickComponent = joystickComponent;
    _switchComponents = switchComponents;
    _numSwitches = sizeof(_switchComponents);
}

void JoystickMouseSubroutine::init()
{
  _joystickComponent.init();

  for (byte i = 0; i < _numSwitches; i++){
    _switchComponents[i].init();
  }

}

void JoystickMouseSubroutine::run()
{
  _joystickComponent.handler();

  for (byte i = 0; i < _numSwitches; i++){
    _switchComponents[i].handler();
  }

}
