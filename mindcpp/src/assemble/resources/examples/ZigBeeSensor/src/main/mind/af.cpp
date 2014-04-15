/*
 * af.cpp
 *
 *  Created on: 19 mars 2014
 *      Author: SESA188919
 */

#include "af.adl.hpp"

void af::DataRequest(unsigned char* a_data)
{
	nwkitf->SendRequest(a_data);
}
