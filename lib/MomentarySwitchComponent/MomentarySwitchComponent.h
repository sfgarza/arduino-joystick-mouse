#ifndef MomentarySwitchComponent_h
#define MomentarySwitchComponent_h

#include "Arduino.h"
#include "MomentarySwitchInterface.h"
class MomentarySwitchComponent: public MomentarySwitchInterface {
   public:
      MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction, void(*onClickCallback)(uint8_t), void(*onReleaseCallback)(uint8_t)):MomentarySwitchInterface(clickPin, ledPin, switchAction){
         _onClickCallback = onClickCallback;
         _onReleaseCallback = onReleaseCallback;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t switchAction, void(*onClickCallback)(uint8_t), void(*onReleaseCallback)(uint8_t)):MomentarySwitchInterface(clickPin, switchAction){
         _onClickCallback = onClickCallback;
         _onReleaseCallback = onReleaseCallback;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction, void(*onToggleCallback)(uint8_t, uint8_t)):MomentarySwitchInterface(clickPin, ledPin, switchAction){
         _onToggleCallback = onToggleCallback;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t switchAction, void(*onToggleCallback)(uint8_t, uint8_t)):MomentarySwitchInterface(clickPin, switchAction){
         _onToggleCallback = onToggleCallback;
      };
      void init();
      void handler();
      void momentaryPresshandler();
      void togglePresshandler();
      void(*_onClickCallback)(uint8_t);
      void(*_onReleaseCallback)(uint8_t);
      void(*_onToggleCallback)(uint8_t, uint8_t);
};

#endif