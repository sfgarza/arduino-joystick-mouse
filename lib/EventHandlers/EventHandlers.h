#ifndef EventHandlers_h
#define EventHandlers_h

#include "Arduino.h"
#include "HID-Project.h"
#include "JoystickComponent.h"

void onMouseClickHandler(uint8_t action);

void onMouseReleaseHandler(uint8_t action);

void onMouseSensitivityHandler(uint8_t action);

void onToggleHandler(uint8_t action, uint8_t actionState);

void doNothing(uint8_t action);

#endif