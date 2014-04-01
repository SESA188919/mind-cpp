/*
 * zigbeestackAPI.hpp
 *
 *  Created on: 20 mars 2014
 *      Author: SESA188919
 */

#ifndef ZIGBEESTACKAPI_HPP_
#define ZIGBEESTACKAPI_HPP_


#include "zigBeeStack_anon_0.adl.hpp"


using namespace __ns_zigBeeStack_anon_0;

class zigbeestackAPI: public zigBeeStack_anon_0Definition {
private:
protected:
public:
	virtual void DataRequest(unsigned char*);
	virtual void Init(void );
};


#endif /* ZIGBEESTACKAPI_HPP_ */
