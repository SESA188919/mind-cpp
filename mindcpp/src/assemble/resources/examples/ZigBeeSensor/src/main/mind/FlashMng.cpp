#include "FlashMng.hpp"
#include <stdio.h>
#include "FlashMngExt.hpp"

void flashmngitf::WritePage(int address, int byte) {
  FlashMngExt flash;
  flash.WriteByte(address, byte);
  //PRIVATE.toto = 2;
  //PRIVATE.tata = 4;
  return;
}


void flashmngitf::ReadPage(int address, int *byte) {
  //	PRIVATE.m_FlashMngExt.ReadByte(address, byte);
  *byte = 1;
  return;
}
