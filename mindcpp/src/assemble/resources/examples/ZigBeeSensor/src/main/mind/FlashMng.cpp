#include "FlashMng.hpp"
#include <stdio.h>
#include "FlashMngExt.hpp"

void flashmngitf::WritePage(int address, int byte) {
  FlashMngExt flash;
  flash.WriteByte(address, byte);
  return;
}


void flashmngitf::ReadPage(int address, int *byte) {
  FlashMngExt flash;
  flash.ReadByte(address, byte);
  return;
}
