/*
 * FlashMng.hpp
 *
 *  Created on: 1 avr. 2014
 *      Author: SESA188919
 */

#ifndef FLASHMNG_HPP_
#define FLASHMNG_HPP_


#include "FlashMng.adl.hpp"

using namespace __ns_FlashMng;

class FlashMng: public FlashMngDefinition {
protected:
public:
  virtual void WritePage(int address, int byte);
  virtual void ReadPage(int address, int *byte);
};



#endif /* FLASHMNG_HPP_ */
