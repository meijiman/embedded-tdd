#include <stdint.h>
#include "LedDriver.h"

static uint16_t * ledsAddress;
static uint16_t ledsImage;

enum {
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};	

void LedDriver_Create(uint16_t * address) {
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	*ledsAddress = ledsImage;
}

void LedDriver_TurnOn(int ledNumber) {
	ledsImage |= 1 << (ledNumber - 1);	
	*ledsAddress = ledsImage;
}

void LedDriver_TurnOff(int ledNumber) {
	ledsImage &= ~(1 << (ledNumber - 1));
	*ledsAddress = ledsImage;
}

void LedDriver_TurnAllOn(void) {
	ledsImage = ALL_LEDS_ON;
	*ledsAddress = ledsImage;
}

