/*
 * sensor.cpp
 *
 *  Created on: 19 mars 2014
 *      Author: SESA188919
 */


#include "sensor.adl.hpp"



/** sensorItf methods */
int sensor::getSensorType() {
	return 2;
}

void sensor::switchOn() {
	printf("Switch ON sensor\n");
}

void sensor::switchOff() {
	printf("Switch OFF sensor\n");
}

void sensor::reset() {
	printf("Reset sensor\n");
}
