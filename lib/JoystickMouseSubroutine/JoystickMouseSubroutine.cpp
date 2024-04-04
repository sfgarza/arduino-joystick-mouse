#include "Arduino.h"
#include "HID-Project.h"
#include "Vector.h"
#include "JoystickMouseSubroutine.h"
#include "JoystickComponent.h"

JoystickMouseSubroutine::JoystickMouseSubroutine(JoystickComponent joystickComponent, Vector<MomentarySwitchComponent> switchComponents ) : _joystickComponent{joystickComponent}, _switchComponents{switchComponents}
{
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
    //_switchComponents[i].togglePresshandler(&onToggleCallback);
    _switchComponents[i].momentaryPresshandler(&onClickCallback, &onReleaseCallback);
  }

}

void JoystickMouseSubroutine::onClickCallback(byte action)
{
    Mouse.press(action);  // click the button down
}

void JoystickMouseSubroutine::onReleaseCallback(byte action)
{
    Mouse.release(action);  // click the button down
}

void JoystickMouseSubroutine::onToggleCallback(byte action, byte actionState)
{
  if (actionState == HIGH ){
    Mouse.press(action);  // click the button down
  }else{
    Mouse.release(action);
  }
}
