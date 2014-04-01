/*
 * zigBeeStack.hpp
 *
 *  Created on: 18 mars 2014
 *      Author: SESA188919
 */

#ifndef ZIGBEESTACK_HPP_
#define ZIGBEESTACK_HPP_

#include "zigBeeStack.adl.hpp"

using namespace __ns_zigBeeStack;

class zigBeeStack: public zigBeeStackDefinition {
protected:
public:
	virtual void DataRequest(unsigned char*);
};


#endif /* ZIGBEESTACK_HPP_ */
