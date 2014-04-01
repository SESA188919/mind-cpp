/*
 * mainComponent.hpp
 *
 *  Created on: 18 mars 2014
 *      Author: SESA188919
 */

#ifndef MAINCOMPONENT_HPP_
#define MAINCOMPONENT_HPP_

#include "mainComponent.adl.hpp"

using namespace __ns_mainComponent;

class mainComponent: public mainComponentDefinition {
protected:
public:
	virtual int main(  int argc, char (* (* argv)) );
};


#endif /* MAINCOMPONENT_HPP_ */
