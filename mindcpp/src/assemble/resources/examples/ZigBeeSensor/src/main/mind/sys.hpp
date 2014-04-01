/*
 * sys.hpp
 *
 *  Created on: 20 mars 2014
 *      Author: SESA188919
 */

#ifndef SYS_HPP_
#define SYS_HPP_


#include "sys.adl.hpp"


using namespace __ns_sys;

class sys: public sysDefinition {
private:
protected:
public:
	virtual void Init(void);
};

#endif /* SYS_HPP_ */
