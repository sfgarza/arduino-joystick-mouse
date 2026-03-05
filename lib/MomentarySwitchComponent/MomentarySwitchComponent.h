#ifndef MomentarySwitchComponent_h
#define MomentarySwitchComponent_h

#include "Arduino.h"
#include "MomentarySwitchInterface.h"
class MomentarySwitchComponent: public MomentarySwitchInterface {
   public:
      MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction, void(*onClickCallback)(uint8_t), void(*onReleaseCallback)(uint8_t)):MomentarySwitchInterface(clickPin, ledPin, switchAction){
         _onClickCallback = onClickCallback;
         _onReleaseCallback = onReleaseCallback;
         _onToggleCallback = nullptr;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t switchAction, void(*onClickCallback)(uint8_t), void(*onReleaseCallback)(uint8_t)):MomentarySwitchInterface(clickPin, switchAction){
         _onClickCallback = onClickCallback;
         _onReleaseCallback = onReleaseCallback;
         _onToggleCallback = nullptr;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t ledPin, uint8_t switchAction, void(*onToggleCallback)(uint8_t, uint8_t)):MomentarySwitchInterface(clickPin, ledPin, switchAction){
         _onClickCallback = nullptr;
         _onReleaseCallback = nullptr;
         _onToggleCallback = onToggleCallback;
      };
      MomentarySwitchComponent(uint8_t clickPin, uint8_t switchAction, void(*onToggleCallback)(uint8_t, uint8_t)):MomentarySwitchInterface(clickPin, switchAction){
         _onClickCallback = nullptr;
         _onReleaseCallback = nullptr;
         _onToggleCallback = onToggleCallback;
      };
      void init();
      void handler();
      void momentaryPressHandler();
      void togglePressHandler();
      void(*_onClickCallback)(uint8_t);
      void(*_onReleaseCallback)(uint8_t);
      void(*_onToggleCallback)(uint8_t, uint8_t);
};

#endif