/*
 * sensor.cpp
 *
 *  Created on: 19 mars 2014
 *      Author: SESA188919
 */


#include "sensor.hpp"



/** sensorItf methods */
int sensoritf::getSensorType() {
	return 2;
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
