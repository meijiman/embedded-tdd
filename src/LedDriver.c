#include <stdint.h>
#include "LedDriver.h"

static uint16_t * ledsAddress;

enum {
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};	

void LedDriver_Create(uint16_t * address) {
	ledsAddress = address;
	*ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_TurnOn(int ledNumber) {
	*ledsAddress |= 1 << (ledNumber - 1);	
}

void LedDriver_TurnOff(int ledNumber) {
	*ledsAddress &= ~(1 << (ledNumber - 1));
}

void LedDriver_TurnAllOn(void) {
	*ledsAddress = ALL_LEDS_ON;
}

