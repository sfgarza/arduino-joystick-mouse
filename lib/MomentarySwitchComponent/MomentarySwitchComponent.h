#ifndef MomentarySwitchComponente_h
#define MomentarySwitchComponent_h

#include "Arduino.h"

class MomentarySwitchComponent {
   public:
      MomentarySwitchComponent(
         uint8_t clickPin,
         uint8_t ledPin
      );
    public:
      MomentarySwitchComponent(
         uint8_t clickPin
      );
      void init();
      void handler(uint8_t mousePress);
   private:
      byte _clickPin;
      byte _ledPin;
      byte _clickFlag;
      bool _hasLED;
};

#endif