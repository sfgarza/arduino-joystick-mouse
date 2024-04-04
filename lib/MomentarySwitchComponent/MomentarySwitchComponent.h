#ifndef MomentarySwitchComponent_h
#define MomentarySwitchComponent_h

#include "Arduino.h"
#include "MomentarySwitchInterface.h"
class MomentarySwitchComponent: public MomentarySwitchInterface {
   public:
      MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction):MomentarySwitchInterface(clickPin, ledPin, switchAction){};
      MomentarySwitchComponent(uint8_t clickPin, uint8_t switchAction):MomentarySwitchInterface(clickPin, switchAction){};
      void init();
      void handler();
      void momentaryPresshandler(void(*onClickCallback)(byte), void(*onReleaseCallback)(byte));
      void togglePresshandler(void(*onToggleCallback)(byte, byte));
};

#endif