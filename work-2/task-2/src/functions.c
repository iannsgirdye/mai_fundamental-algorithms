#include "../include/functions.h"


void *memchr(const void *str, int c, size_t n) {
  const unsigned char *_str = (unsigned char *)str;
  const unsigned char _c = (unsigned char *)c;
  for (size_t i = 0; i != n; ++i) {
    if (_str[i] == _c) {
      return (void *)(_str + i);
    }
  }
  return NULL;
}
