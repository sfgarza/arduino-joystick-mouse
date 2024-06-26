#include "Arduino.h"
#include <HID-Project.h>
#include <VolumeEncoderSubroutine.h>

VolumeEncoderSubroutine::VolumeEncoderSubroutine(uint8_t inputCLK, uint8_t inputDT, uint8_t inputSW){
 _inputCLK = inputCLK;
 _inputDT = inputDT;
 _inputSW = inputSW;
}

void VolumeEncoderSubroutine::init() {
	// Set encoder pins as inputs
	pinMode (_inputCLK,INPUT);
	pinMode (_inputDT,INPUT);
	pinMode(_inputSW, INPUT_PULLUP);

	Consumer.begin();
	Keyboard.begin();

	// Read the initial state of inputCLK
	// Assign to previousStateCLK variable
	_previousStateCLK = digitalRead(_inputCLK);
}

void VolumeEncoderSubroutine::run() {
	// Read the current state of inputCLK
	_currentStateCLK = digitalRead(_inputCLK);

	// If the previous and the current state of the inputCLK are different then a pulse has occured
	if (_currentStateCLK != _previousStateCLK ){
		// If the inputDT state is different than the inputCLK state then
		// the encoder is rotating counterclockwise
		if (digitalRead(_inputDT) != _currentStateCLK) {
			rotateRight();
		} else {
			rotateLeft();
		}
	}
	// Update previousStateCLK with the current state
	_previousStateCLK = _currentStateCLK;

    //Mute
    _currentStateSW = digitalRead(_inputSW); // Button Value

    if (_currentStateSW == LOW)
    { // Switch pushed

        if (millis() - _lastButtonPress > 1100)
        { // Over 1.1s
            Consumer.write(MEDIA_VOLUME_MUTE);
			delay(1000);
        }
        _lastButtonPress = millis();
    }

}

void VolumeEncoderSubroutine::rotateRight() {
	// Increase the volume.
	Consumer.write(MEDIA_VOLUME_UP);
}

void VolumeEncoderSubroutine::rotateLeft() {
	// Decrease the volume.
	Consumer.write(MEDIA_VOLUME_DOWN);
}