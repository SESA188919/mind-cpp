/*
 * main.cpp
 *
 *  Created on: 16 janv. 2014
 *      Author: SESA188919
 */


/**
 * Generated code
 */

#include <stdio.h>
#include "zigBeeSensor.adl.hpp"


int main(int argc, char *argv[]) {
	zigBeeSensor baseComposite;
	baseComposite.getBootStrapComponent()->Construct();


	// Bind all sub-components
	baseComposite.getBootStrapComponent()->Init();

	// Run the application
	baseComposite.getBootStrapComponent()->main(argc, argv);


	baseComposite.getBootStrapComponent()->Destroy();
}
