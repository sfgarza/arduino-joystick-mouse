#ifndef JoystickMouseSubroutine_h
#define JoystickMouseSubroutine_h


class JoystickMouseSubroutine {
   public:
      JoystickMouseSubroutine(uint8_t horzPin, uint8_t vertPin, uint8_t selPin, int invertMouse);
      void init();
      void run();
   private:
      byte _horzPin;
      byte _vertPin;
      byte _selPin;
      byte _mouseClickFlag;
      int _vertZero;
      int _horzZero;
      int _vertValue;
      int _horzValue;
      int _invertMouse;
      static const int SENSITIVITY = 200;
};

#endif