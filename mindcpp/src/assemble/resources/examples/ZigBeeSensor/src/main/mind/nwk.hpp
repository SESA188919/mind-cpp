/*
 * nwk.hpp
 *
 *  Created on: 19 mars 2014
 *      Author: SESA188919
 */

#ifndef NWK_HPP_
#define NWK_HPP_

#include "nwk.adl.hpp"

using namespace __ns_nwk;

class nwk: public nwkDefinition {
protected:
public:
	virtual void SendRequest(unsigned char*);
};


#endif /* NWK_HPP_ */
