#ifndef MomentarySwitchComponent_h
#define MomentarySwitchComponent_h

#include "Arduino.h"
#include "MomentarySwitchInterface.h"
class MomentarySwitchComponent: public MomentarySwitchInterface {
   public:
      MomentarySwitchComponent(
         uint8_t clickPin,
         uint8_t ledPin,
         uint8_t mouseAction
      );
    public:
      MomentarySwitchComponent(
         uint8_t clickPin,
         uint8_t mouseAction
      );
      void init();
      void handler();
   private:
      byte _mouseAction;
};

#endif