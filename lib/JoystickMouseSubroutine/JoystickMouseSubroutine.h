#ifndef JoystickMouseSubroutine_h
#define JoystickMouseSubroutine_h

#include "Vector.h"
#include "Arduino.h"
#include "MomentarySwitchInterface.h"
#include "MomentarySwitchComponent.h"
#include "JoystickComponent.h"
class JoystickMouseSubroutine {
   public:
      JoystickMouseSubroutine(
         JoystickComponent joystickComponent,
         Vector<MomentarySwitchComponent> switchComponents
      );
      void init();
      void run();
   private:
      byte _numSwitches;
      JoystickComponent _joystickComponent;
      Vector<MomentarySwitchComponent> _switchComponents;
};

#endif