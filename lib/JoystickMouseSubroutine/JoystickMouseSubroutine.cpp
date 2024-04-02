/* HID Joystick Mouse Example
   by: Jim Lindblom
   date: 1/12/2012
   license: MIT License - Feel free to use this code for any purpose.
   No restrictions. Just keep this license if you go on to use this
   code in your future endeavors! Reuse and share.

   This is very simplistic code that allows you to turn the
   SparkFun Thumb Joystick (http://www.sparkfun.com/products/9032)
   into an HID Mouse. The select button on the joystick is set up
   as the mouse left click.
*/
#include "Arduino.h"
#include "HID-Project.h"
#include "JoystickMouseSubroutine.h"

JoystickMouseSubroutine::JoystickMouseSubroutine(uint8_t horzPin, uint8_t vertPin, int invertMouse, int sensitivity, uint8_t leftClickPin, uint8_t rightClickPin, uint8_t middleClickPin, uint8_t leftLedPin, uint8_t rightLedPin, uint8_t middleLedPin){
    _horzPin = horzPin;
    _vertPin = vertPin;
    _invertMouse = invertMouse;
    _sensitivity = sensitivity;
    _leftClickPin = leftClickPin;
    _rightClickPin = rightClickPin;
    _middleClickPin = middleClickPin;
    _leftLedPin = leftLedPin;
    _rightLedPin = rightLedPin;
    _middleLedPin = middleLedPin;
}

void JoystickMouseSubroutine::init()
{
  pinMode(_horzPin, INPUT);  // Set both analog pins as inputs
  pinMode(_vertPin, INPUT);
  pinMode(_leftClickPin, INPUT);  // set button select pin as input
  digitalWrite(_leftClickPin, HIGH);  // Pull button select pin high
  pinMode(_rightClickPin, INPUT);  // set button select pin as input
  digitalWrite(_rightClickPin, HIGH);  // Pull button select pin high
  pinMode(_middleClickPin, INPUT);  // set button select pin as input
  digitalWrite(_middleClickPin, HIGH);  // Pull button select pin high
  pinMode(_leftLedPin, OUTPUT);
  pinMode(_rightLedPin, OUTPUT);
  pinMode(_middleLedPin, OUTPUT);
  delay(1000);  // short delay to let outputs settle
  _vertZero = analogRead(_vertPin);  // get the initial values
  _horzZero = analogRead(_horzPin);  // Joystick should be in neutral position when reading these

  Mouse.begin(); //Init mouse emulation
}

void JoystickMouseSubroutine::run()
{
  _vertValue = analogRead(_vertPin) - _vertZero;  // read vertical offset
  _horzValue = analogRead(_horzPin) - _horzZero;  // read horizontal offset

  if (_vertValue != 0)
    Mouse.move(0, (_invertMouse * (_vertValue / _sensitivity)), 0); // move mouse on y axis
  if (_horzValue != 0)
    Mouse.move((-_invertMouse * (_horzValue / _sensitivity)), 0, 0); // move mouse on x axis

  buttonHandler(MOUSE_LEFT, true);
  buttonHandler(MOUSE_RIGHT, true);
  buttonHandler(MOUSE_MIDDLE, true);

}

void JoystickMouseSubroutine::buttonHandler(uint8_t mousePress, bool hasLED)
{
  byte clickPin;
  byte *clickFlag;
  byte ledPin;

  switch (mousePress)
  {
  case MOUSE_LEFT:
    clickPin = _leftClickPin;
    clickFlag = &_leftClickFlag;
    if(hasLED){
      ledPin = _leftLedPin;
    }
    break;
  case MOUSE_RIGHT:
    clickPin = _rightClickPin;
    clickFlag = &_rightClickFlag;
    if(hasLED){
      ledPin = _rightLedPin;
    }
    break;
  case MOUSE_MIDDLE:
    clickPin = _middleClickPin;
    clickFlag = &_middleClickFlag;
    if(hasLED){
      ledPin = _middleLedPin;
    }
    break;
  }

  if ((digitalRead(clickPin) == 0) && (!*clickFlag))  // if the button is pressed
  {
    *clickFlag = 1;
    if(hasLED){
      digitalWrite(ledPin, HIGH);
    }
    Mouse.press(mousePress);  // click the button down
  }else if ((digitalRead(clickPin)) && (*clickFlag)) // if the  button is not pressed
  {
    *clickFlag = 0;
    if(hasLED){
      digitalWrite(ledPin, LOW);
    }
    Mouse.release(mousePress);  // release the button
  }
}