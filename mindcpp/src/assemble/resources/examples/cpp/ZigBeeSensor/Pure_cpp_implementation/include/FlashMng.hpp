/*
 * FlashMng.hpp
 *
 *  Created on: 1 avr. 2014
 *      Author: SESA188919
 */

#ifndef FLASHMNG_HPP_
#define FLASHMNG_HPP_


#include "FlashMng.itf.hpp"

class FlashMng : public FlashMngItf {

public:
  virtual void WritePage(int address, int byte);
  virtual void ReadPage(int address, int *byte);
};



#endif /* FLASHMNG_HPP_ */
