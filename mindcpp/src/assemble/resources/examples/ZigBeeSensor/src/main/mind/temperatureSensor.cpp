#include <stdio.h>
#include "temperatureSensor.adl.hpp"

// -----------------------------------------------------------------------------
// Implementation of the primitive sensor.
// -----------------------------------------------------------------------------


/**
 * Get the current temperature (unit = degree celcius)
 * The value is a integer on 16bits.
 * The coefficient is x100.
 * ex: for 20°C => value = 2000
 */
unsigned char temperatureSensor::GetCurrentTemperature(signed short *data) {
	*data = 2730;
	printf("Current temperature is %d\n", *data);
	return 0;
}
/**
 * Get the maximum temperature (unit = degree celcius)
 * The value is a integer on 16bits.
 * The coefficient is x100.
 * ex: for 20°C => value = 2000
 */
unsigned char temperatureSensor::GetMaxTemperature(signed short *data) {
	*data = 3540;
	return 0;
}
/**
 * Get the minimum temperature (unit = degree celcius)
 * The value is a integer on 16bits.
 * The coefficient is x100.
 * ex: for 20°C => value = 2000
 */
unsigned char temperatureSensor::GetMinTemperature(signed short *data) {
	*data = 1020;
	return 0;
}
/**
 * Get the temperature accuracy
 */
unsigned char temperatureSensor::GetTemperatureAccuracy(unsigned short *data) {
	*data = 1;
	return 0;
}

int temperatureSensor::getSensorType() {
	return 15;
}

void temperatureSensor::switchOn() {
	printf("Switch ON sensor\n");
}

void temperatureSensor::switchOff() {
	printf("Switch OFF sensor\n");
}

void temperatureSensor::reset() {
	printf("Reset sensor\n");
}
