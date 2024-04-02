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

JoystickMouseSubroutine::JoystickMouseSubroutine(uint8_t horzPin, uint8_t vertPin, int invertMouse, int sensitivity, uint8_t leftClickPin, uint8_t rightClickPin, uint8_t middleClickPin){
    _horzPin = horzPin;
    _vertPin = vertPin;
    _invertMouse = invertMouse;
    _sensitivity = sensitivity;
    _leftClickPin = leftClickPin;
    _rightClickPin = rightClickPin;
    _middleClickPin = middleClickPin;
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
    Mouse.move((_invertMouse * (_horzValue / _sensitivity)), 0, 0); // move mouse on x axis

  if ((digitalRead(_leftClickPin) == 0) && (!_leftClickFlag))  // if the joystick button is pressed
  {
    _leftClickFlag = 1;
    Mouse.press(MOUSE_LEFT);  // click the left button down
  }else if ((digitalRead(_leftClickPin)) && (_leftClickFlag)) // if the joystick button is not pressed
  {
    _leftClickFlag = 0;
    Mouse.release(MOUSE_LEFT);  // release the left button
  }

  if ((digitalRead(_rightClickPin) == 0) && (!_rightClickFlag))  // if the joystick button is pressed
  {
    _rightClickFlag = 1;
    Mouse.press(MOUSE_RIGHT);  // click the left button down
  }else if ((digitalRead(_rightClickPin)) && (_rightClickFlag)) // if the joystick button is not pressed
  {
    _rightClickFlag = 0;
    Mouse.release(MOUSE_RIGHT);  // release the left button
  }

  if ((digitalRead(_middleClickPin) == 0) && (!_middleClickFlag))  // if the joystick button is pressed
  {
    _middleClickFlag = 1;
    Mouse.press(MOUSE_MIDDLE);  // click the left button down
  }else if ((digitalRead(_middleClickPin)) && (_middleClickFlag)) // if the joystick button is not pressed
  {
    _middleClickFlag = 0;
    Mouse.release(MOUSE_MIDDLE);  // release the left button
  }



}
