#include "../include/functions.h"
#include "../include/errno.h"
#include <stdbool.h>
#include <stdio.h>


#define FIRST_LESS_SECOND -1
#define FIRST_EQUAL_SECOND 0
#define FIRST_GREATER_SECOND 1
#define NO_NEEDLE_START -1
#define STRTOK_START_FROM_NULL true


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


char *strncat(char *dest, const char *src, size_t n) {
  const size_t destLen = strlen(dest);

  for (size_t i = 0; i != n; ++i) {
    dest[destLen + i] = src[i];
  }
  dest[destLen + n] = '\0';
  
  return dest;
}


char *strchr(const char *str, int c) {
  const size_t strLen = strlen(str);
  const unsigned char _c = (unsigned char)c;

  for (size_t i = 0; i != strLen; ++i) {
    if (str[i] == _c) {
      return (char *)(str + i);
    }
  }
  return NULL;
}


int strncmp(const char *str1, const char *str2, size_t n) {
  for (size_t i = 0; i != n; ++i) {
    if (str1[i] < str2[i]) {
      return FIRST_LESS_SECOND;
    }
    if (str1[i] > str2[i]) {
      return FIRST_GREATER_SECOND;
    }
  }
  return FIRST_EQUAL_SECOND;
}


char *strncpy(char *dest, const char *src, size_t n) {
  for (size_t i = 0; i != n; ++i) {
    dest[i] = src[i];
  }
  return dest;
}


size_t strcspn(const char *str1, const char *str2) {
  const size_t str1Len = strlen(str1);
  const size_t str2Len = strlen(str2);
  
  for (size_t i = 0; i != str1Len; ++i) {
    for (size_t j = 0; j != str2Len; ++j) {
      if (str1[i] == str2[j]) {
        return i;
      }
    }
  }
  return str1Len;
}


char *strerror(int errnum) {
  if (errnum < 0 || errnum > MAX_ERRNO) {
    return "Unknown error";
  }
  return (char *)errors[errnum];
}


size_t strlen(const char *str) {
  size_t i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}


char *strpbrk(const char *str1, const char *str2) {
  const size_t str1Len = strlen(str1);
  const size_t str2Len = strlen(str2);

  for (size_t i = 0; i != str1Len; ++i) {
    for (size_t j = 0; j != str2Len; ++j) {
      if (str1[i] == str2[j]) {
        return (char *)(str1 + i);
      }
    }
  }
  return NULL;
}


char *strrchr(const char *str, int c) {
  char *lastC = NULL;
  const size_t strLen = strlen(str);
  const char _c = (char)c;

  for (size_t i = 0; i != strLen; ++i) {
    if (str[i] == _c) {
      lastC = (char *)(str + i);
    }
  }

  return lastC;
}


bool _isNotFoundNeedleStart(const int iNeedleStart) {
  return iNeedleStart == NO_NEEDLE_START;
}


bool _isFindNeedleEnd(const char needleLetter) {
  return needleLetter == '\0';
}


bool _isNotFoundNeedleFully(const size_t haystackLen, const size_t needleLen, const int iNeedleStart) {
  return haystackLen < iNeedleStart + needleLen;
}


char *strstr(const char *haystack, const char *needle) {
  const size_t haystackLen = strlen(haystack);
  const size_t needleLen = strlen(needle);
  int iNeedleStart = NO_NEEDLE_START;

  if (needleLen == 0) {
    return (char *)haystack;
  }

  for (size_t i = 0; i != haystackLen; ++i) {
    if (_isNotFoundNeedleStart(iNeedleStart)) {
      if (haystack[i] == needle[0]) {
        iNeedleStart = i;
      }
    } else if (_isFindNeedleEnd(needle[i - iNeedleStart])) {
      break;
    } else if (haystack[i] != needle[i - iNeedleStart]) {
      iNeedleStart = NO_NEEDLE_START;
    }
  }

  if (_isNotFoundNeedleStart(iNeedleStart)) {
    return NULL;
  }
  if (_isNotFoundNeedleFully(haystackLen, needleLen, iNeedleStart)) {
    return NULL;
  }
  return (char *)(haystack + iNeedleStart);
}


bool _initStrtokValues(char *str, char **iter, char **start) {
  if (str == NULL) {
    if (*iter == NULL) {
      return STRTOK_START_FROM_NULL;
    } 
    ++(*iter);
    *start = *iter;
  } else {
    *iter = str;
    *start = str;
  }

  return !STRTOK_START_FROM_NULL;
}


char *strtok(char *str, const char *delim) {
  static char *iter = NULL;
  static char *start = NULL;

  if (_initStrtokValues(str, &iter, &start) == STRTOK_START_FROM_NULL) {
    return NULL;
  }
  
  while (*iter != '\0') {
    if (strchr(delim, *iter) != NULL) {
      *iter = '\0';
      return start;
    }
    ++iter;
  }
  
  return start;
}
