#ifndef MomentarySwitchInterface_h
#define MomentarySwitchInterface_h

#include "Arduino.h"

class MomentarySwitchInterface
{
public:
    MomentarySwitchInterface(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction): _clickPin{clickPin}, _ledPin(ledPin), _switchAction(switchAction), _clickFlag(false), _hasLED(true), _lastState(HIGH), _currentState(HIGH), _actionState(LOW){};
    MomentarySwitchInterface(uint8_t clickPin, uint8_t switchAction) : _clickPin{clickPin}, _switchAction(switchAction), _clickFlag(false),_hasLED(false), _lastState(LOW), _currentState(LOW),_actionState(LOW){};
    void init()
    {
        pinMode(_clickPin, INPUT);     // set button select pin as input
        digitalWrite(_clickPin, HIGH); // Pull button select pin high
        if (_hasLED)
        {
            pinMode(_ledPin, OUTPUT);
        }
    };
protected:
    byte _clickPin;
    byte _ledPin;
    int _switchAction;
    bool _clickFlag;
    bool _hasLED;
    byte _lastState;
    byte _currentState;
    byte _actionState;

};

#endif