#ifndef JoystickComponent_h
#define JoystickComponent_h

#include "Vector.h"
#include "Arduino.h"

class JoystickComponent {
   public:
      JoystickComponent(
         uint8_t horzPin,
         uint8_t vertPin,
         int invertX,
         int invertY,
         int sensitivity
      );
      void init();
      void handler();
   private:
      byte _horzPin;
      byte _vertPin;
      byte _numSwitches;
      int _vertZero;
      int _horzZero;
      int _vertValue;
      int _horzValue;
      int _invertX;
      int _invertY;
      int _sensitivity;
};

#endif