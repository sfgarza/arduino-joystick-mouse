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

	// Setup Serial Monitor
	//Serial.begin (9600);
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
	if (_currentStateCLK != _previousStateCLK){
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
}

void VolumeEncoderSubroutine::rotateRight() {
	// Increase the volume.
	Consumer.write(MEDIA_VOLUME_UP);
}

void VolumeEncoderSubroutine::rotateLeft() {
	// Decrease the volume.
	Consumer.write(MEDIA_VOLUME_DOWN);
}