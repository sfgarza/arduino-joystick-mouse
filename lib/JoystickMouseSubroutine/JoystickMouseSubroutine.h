#ifndef JoystickMouseSubroutine_h
#define JoystickMouseSubroutine_h

#include "Vector.h"
#include "Arduino.h"
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"
class JoystickMouseSubroutine {
   public:
      JoystickMouseSubroutine(
         uint8_t horzPin,
         uint8_t vertPin,
         int invertMouse,
         int sensitivity,
         Vector<MomentarySwitchComponent> *switchComponents
      );
      void init();
      void run();
   private:
      byte _horzPin;
      byte _vertPin;
      byte _numSwitches;
      Vector<MomentarySwitchComponent> _switchComponents;
      int _vertZero;
      int _horzZero;
      int _vertValue;
      int _horzValue;
      int _invertMouse;
      int _sensitivity;
};

#endif