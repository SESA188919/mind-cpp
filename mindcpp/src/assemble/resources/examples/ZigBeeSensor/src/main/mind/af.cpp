/*
 * af.cpp
 *
 *  Created on: 19 mars 2014
 *      Author: SESA188919
 */

#include "af.hpp"

void afitf::DataRequest(unsigned char* a_data)
{
	nwkitf.SendRequest(a_data);
}
