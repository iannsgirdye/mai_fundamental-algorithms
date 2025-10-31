#include "../include/functions.h"


#define FIRST_LESS_SECOND -1
#define FIRST_EQUAL_SECOND 0
#define FIRST_GREATER_SECOND 1


void *memchr(const void *str, int c, size_t n) {
  const unsigned char *_str = (unsigned char *)str;
  const unsigned char _c = (unsigned char)c;
  
  for (size_t i = 0; i != n; ++i) {
    if (_str[i] == _c) {
      return (void *)(_str + i);
    }
  }
  return NULL;
}


int memcmp(const void *str1, const void *str2, size_t n) {
  const unsigned char *_str1 = (unsigned char *)str1;
  const unsigned char *_str2 = (unsigned char *)str2;
  
  for (size_t i = 0; i != n; ++i) {
    if (_str1[i] < _str2[i]) {
      return FIRST_LESS_SECOND;
    }
    if (_str1[i] > _str2[i]) {
      return FIRST_GREATER_SECOND;
    }
  }
  return FIRST_EQUAL_SECOND;
}


void *memcpy(void *dest, const void *src, size_t n) {
  unsigned char *_dest = (unsigned char *)dest;
  const unsigned char *_src = (unsigned char *)src;

  for (size_t i = 0; i != n; ++i) {
    _dest[i] = _src[i];
  }
  
  return (void *)_dest;
}


void *memset(void *str, int c, size_t n) {
  unsigned char *_str = (unsigned char *)str;
  const unsigned char _c = (unsigned char)c;

  for (size_t i = 0; i != n; ++i) {
    _str[i] = _c;
  }

  return (void *)_str;
}
