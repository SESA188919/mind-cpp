#include <stdio.h>
#include "temperatureSensor.hpp"

// -----------------------------------------------------------------------------
// Implementation of the primitive sensor.
// -----------------------------------------------------------------------------


/**
 * Get the current temperature (unit = degree celcius)
 * The value is a integer on 16bits.
 * The coefficient is x100.
 * ex: for 20°C => value = 2000
 */
unsigned char temperatureitf::GetCurrentTemperature(signed short *data) {
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
unsigned char  temperatureitf::GetMaxTemperature(signed short *data) {
	*data = 3540;
	return 0;
}
/**
 * Get the minimum temperature (unit = degree celcius)
 * The value is a integer on 16bits.
 * The coefficient is x100.
 * ex: for 20°C => value = 2000
 */
unsigned char temperatureitf::GetMinTemperature(signed short *data) {
	*data = 1020;
	return 0;
}
/**
 * Get the temperature accuracy
 */
unsigned char temperatureitf::GetTemperatureAccuracy(unsigned short *data) {
	*data = 1;
	return 0;
}

int sensoritf::getSensorType() {
	return 15;
}

void sensoritf::switchOn() {
	printf("Switch ON sensor\n");
}

void sensoritf::switchOff() {
	printf("Switch OFF sensor\n");
}

void sensoritf::reset() {
	printf("Reset sensor\n");
}
