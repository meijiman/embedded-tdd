#include <stdint.h>
#include <stdbool.h>
#include "LedDriver.h"

static uint16_t * ledsAddress;
static uint16_t ledsImage;

enum {
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};	

enum {
	FIRST_LED = 1,
	LAST_LED = 16	
};

static void updateHardware(void) {
	*ledsAddress = ledsImage;
}

static bool IsLedOutOfBounds(int ledNumber) {
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

void LedDriver_Create(uint16_t * address) {
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_TurnOn(int ledNumber) {
	if (IsLedOutOfBounds(ledNumber))
		return;
	ledsImage |= 1 << (ledNumber - 1);	
	updateHardware();
}

void LedDriver_TurnOff(int ledNumber) {
	if (IsLedOutOfBounds(ledNumber))
		return;
	ledsImage &= ~(1 << (ledNumber - 1));
	updateHardware();
}

void LedDriver_TurnAllOn(void) {
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

