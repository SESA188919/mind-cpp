/*
 * temperatureSensor.hpp
 *
 *  Created on: 18 mars 2014
 *      Author: SESA188919
 */

#ifndef TEMPERATURESENSOR_HPP_
#define TEMPERATURESENSOR_HPP_

#include "temperatureSensor.adl.hpp"
//#include "sensor.adl.hpp"

using namespace __ns_temperatureSensor;

class temperatureSensor: public temperatureSensorDefinition {
private:
protected:
public:
	virtual unsigned char GetCurrentTemperature(signed short *data);

	virtual unsigned char GetMaxTemperature(signed short *data);

	virtual unsigned char GetMinTemperature(signed short *data);

	virtual unsigned char GetTemperatureAccuracy(unsigned short *data);

	/** methods from inheritance of sensorItf interface. */
	virtual int getSensorType();

	virtual void switchOn();

	virtual void switchOff();

	virtual void reset();
};



#endif /* TEMPERATURESENSOR_HPP_ */
