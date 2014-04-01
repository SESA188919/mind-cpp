#include <stdio.h>
#include "zigBeeStack.hpp"

// -----------------------------------------------------------------------------
// Implementation of the primitive ZigBeeStack.
// -----------------------------------------------------------------------------




void zigbeestack::DataRequest(unsigned char* a_data) {
	printf("Send data to the ZigBee network : h%x h%x\n", a_data[0], a_data[1]);
}
