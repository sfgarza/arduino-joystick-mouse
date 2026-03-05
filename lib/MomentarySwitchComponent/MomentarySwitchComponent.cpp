#include "Arduino.h"
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"

void MomentarySwitchComponent::init()
{
  MomentarySwitchInterface::init();
}

void MomentarySwitchComponent::momentaryPressHandler(){
  if ((digitalRead(_clickPin) == 0) && (!_clickFlag)) // if the button is pressed
  {
    _clickFlag = 1;
    if (_hasLED)
    {
      digitalWrite(_ledPin, HIGH);
    }
    if (_onClickCallback) _onClickCallback(_switchAction);
    delay(100);
  }
  else if ((digitalRead(_clickPin)) && (_clickFlag)) // if the button is not pressed
  {
    _clickFlag = 0;
    if (_hasLED)
    {
      digitalWrite(_ledPin, LOW);
    }
    if (_onReleaseCallback) _onReleaseCallback(_switchAction);
  }
}

void MomentarySwitchComponent::togglePressHandler()
{
  _lastState = _currentState;           // save the last state
  _currentState = digitalRead(_clickPin); // read new state

  if (_lastState == HIGH && _currentState == LOW)
  {

    // toggle state of LED
    _actionState = !_actionState;

    if (_hasLED)
    {
      // control LED according to the toggled state
      digitalWrite(_ledPin, _actionState);
    }
    if (_onToggleCallback) _onToggleCallback(_switchAction, _actionState);
    delay(50);
  }
}
