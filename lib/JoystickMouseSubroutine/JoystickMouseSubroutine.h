#ifndef JoystickMouseSubroutine_h
#define JoystickMouseSubroutine_h

#include "Arduino.h"

class JoystickMouseSubroutine {
   public:
      JoystickMouseSubroutine(
         uint8_t horzPin,
         uint8_t vertPin,
         int invertMouse,
         int sensitivity,
         uint8_t leftClickPin,
         uint8_t rightClickPin,
         uint8_t middleClickPin,
         uint8_t leftLedPin,
         uint8_t rightLedPin,
         uint8_t middleLedPin
      );
      void init();
      void run();
   private:
      void buttonHandler(uint8_t mousePress, bool hasLED);
      byte _horzPin;
      byte _vertPin;
      byte _leftClickPin;
      byte _rightClickPin;
      byte _middleClickPin;
      byte _leftLedPin;
      byte _rightLedPin;
      byte _middleLedPin;
      byte _leftClickFlag;
      byte _rightClickFlag;
      byte _middleClickFlag;
      int _vertZero;
      int _horzZero;
      int _vertValue;
      int _horzValue;
      int _invertMouse;
      int _sensitivity;
};

#endif