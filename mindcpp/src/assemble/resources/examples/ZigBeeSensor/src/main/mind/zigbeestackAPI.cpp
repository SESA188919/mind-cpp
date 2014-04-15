/*
 * zigbeestackAPI.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: SESA188919
 */

#include "zigBeeStack_anon_0.adl.hpp"


void zigBeeStack_anon_0::DataRequest(unsigned char*a_data) {
	return afitf->DataRequest(a_data);
}

void zigBeeStack_anon_0::Init(void ) {
	return sysitf->Init();
}
