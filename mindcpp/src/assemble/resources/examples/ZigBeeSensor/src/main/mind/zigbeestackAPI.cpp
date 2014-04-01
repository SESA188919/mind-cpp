/*
 * zigbeestackAPI.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: SESA188919
 */

#include "zigbeestackAPI.hpp"


void zigbeeitf::DataRequest(unsigned char*a_data) {
	return afitf.DataRequest(a_data);
}

void zigbeeitf::Init(void ) {
	return sysitf.Init();
}
