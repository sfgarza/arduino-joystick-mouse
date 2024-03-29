#ifndef VolumeEncoderSubroutine_h
#define VolumeEncoderSubroutine_h

#include "Arduino.h"

class VolumeEncoderSubroutine {
   public:
      VolumeEncoderSubroutine(uint8_t inputCLK, uint8_t inputDT, uint8_t inputSW);
      void init();
      void run();
   private:
      byte _inputCLK;
      byte _inputDT;
      byte _inputSW;
      byte _currentStateSW;
      byte _lastButtonPress;
      int  _currentStateCLK;
      int  _previousStateCLK;
      void rotateRight();
      void rotateLeft();
};

#endif