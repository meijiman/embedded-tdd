#include <stdio.h>
#include <unity.h>
#include "LedDriver.h"

static uint16_t virtualLeds;

void test_ledsOffAfterCreate(void) {
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_turnOnLedOne(void) {
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

void test_turnOffLedOne() {
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_turnOnMultipleLeds() {
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

void test_turnOffAnyLed() {
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}

void test_allOn() {
	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ledsOffAfterCreate);
	RUN_TEST(test_turnOnLedOne);
	RUN_TEST(test_turnOffLedOne);
	RUN_TEST(test_turnOnMultipleLeds);
	RUN_TEST(test_turnOffAnyLed);
	RUN_TEST(test_allOn);
	return UNITY_END();
}

void setUp(void) {
	LedDriver_Create(&virtualLeds);
}

void tearDown(void) {

}

