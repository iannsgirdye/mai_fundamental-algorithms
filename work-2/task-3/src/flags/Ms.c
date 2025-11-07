#include "../../include/flags.h"
#include "../../include/returnStatus.h"
#include <stdlib.h>
#include <stdio.h>


#define BITS_COUNT 8
#define MASK 128


size_t _bytesCount(const char type) {
  switch (type) {
    case 'i': return sizeof(int);
    case 'u': return sizeof(unsigned int);
    case 'f': return sizeof(float);
    default: return sizeof(double);
  }
}


void _convertByte(const char byte, const size_t iByte, char *dump) {
  const size_t iStart = BITS_COUNT * iByte + iByte;
  for (size_t i = iStart; i != iStart + BITS_COUNT; ++i) {
    dump[i] = ((byte << (i - iStart)) & MASK) ? '1' : '0';
  }
}


void _separateBytes(const size_t iByte, char *dump) {
  const size_t iSpace = BITS_COUNT * (iByte + 1) + iByte;
  dump[iSpace] = ' ';
}


void _closeDump(const size_t bytesCount, char *dump) {
  const size_t iSpace = BITS_COUNT * bytesCount + bytesCount - 1;
  dump[iSpace] = '\0';
}


returnStatus flagsM(const void *number, const char type, char *dump) {
  const char *_number = (const char *)number;
  const size_t bytesCount = _bytesCount(type);

  for (size_t i = 0; i != bytesCount; ++i) {
    _convertByte(_number[i], i, dump);
    if (i != bytesCount - 1) {
      _separateBytes(i, dump);
    }
  }
  _closeDump(bytesCount, dump);
  
  return OK;
}
