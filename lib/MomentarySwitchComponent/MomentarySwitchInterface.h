#ifndef MomentarySwitchInterface_h
#define MomentarySwitchInterface_h

#include "Arduino.h"

class MomentarySwitchInterface
{
public:
    MomentarySwitchInterface(uint8_t clickPin, uint8_t ledPin)
    {
        _clickPin = clickPin;
        _ledPin = ledPin;
        _hasLED = true;
    };
    MomentarySwitchInterface(uint8_t clickPin)
    {
        _clickPin = clickPin;
        _hasLED = false;
    };
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
    byte _clickFlag;
    bool _hasLED;
};

#endif