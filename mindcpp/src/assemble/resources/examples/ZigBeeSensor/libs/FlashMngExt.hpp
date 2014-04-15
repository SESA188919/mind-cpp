/*
 * FlashMng.hpp
 *
 *  Created on: 1 avr. 2014
 *      Author: yves
 */

#ifndef FLASHMNGEXT_HPP_
#define FLASHMNGEXT_HPP_


class FlashMngExt {
public:
    FlashMngExt() {};
	~FlashMngExt() {};
	void WriteByte(int address, int byte);
	void ReadByte(int address, int *byte);
};


#endif /* FLASHMNGEXT_HPP_ */
