#include "../include/overFunctions.h"
#include "../include/flags.h"
#include "../include/customString.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>


#define TRUE  1
#define FALSE 0

#define ROMAN_DIGITS_COUNT      7
#define ZECKENDORF_DIGITS_COUNT 2

#define MIN_SYSTEM  2
#define MAX_SYSTEM 36


enum lenFlag {
  SPECIAL_FLAG_LEN = 3,
  NO_PREFIX_FLAG_LEN = 2,
  x1_PREFIX_FLAG_LEN = 3,
  x2_PREFIX_FLAG_LEN = 4
};

typedef enum typeFlag {
  DEFAULT_FLAG,
  SPECIAL_FLAG,
  INVALID_FLAG
} typeFlag;


int _defineSpecialFlag(const char *_Format, const size_t i, char *flag) {
  strncpy(flag, &_Format[i], SPECIAL_FLAG_LEN);
  flag[SPECIAL_FLAG_LEN] = '\0';
  
  const char *specialFlags = "%Ro%Zr%Cv%CV";
  return strstr(specialFlags, flag) != NULL;
} 


void _defineDefaultFlag(const char *_Format, const size_t i, char *flag) {
  size_t len;

  switch (_Format[i + 1]) {
    case 'z':
      len = x1_PREFIX_FLAG_LEN;
      break;
    case 'h':
    case 'l':
      len = (_Format[i + 1] == _Format[i + 2]) ? x2_PREFIX_FLAG_LEN : x1_PREFIX_FLAG_LEN;
      break;
    default:
      len = NO_PREFIX_FLAG_LEN;
  }

  strncpy(flag, &_Format[i], len);
  flag[len] = '\0';
}


typeFlag _parseFlag(const char *_Format, size_t i, char *flag) {
  if (_Format[i + 1] == '\0') {
    return INVALID_FLAG;
  } 
  if (isalpha(_Format[i + 1]) && isalpha(_Format[i + 2])) {
    if (_defineSpecialFlag(_Format, i, flag)) {
      return SPECIAL_FLAG;
    }
  }
  _defineDefaultFlag(_Format, i, flag);
  return DEFAULT_FLAG;
}


int _isCorrectSpecialDigit(const char *flag, const char digit, int *system) {
  if (strcmp(flag, "%Ro") == 0) {
    return strchr("IVXLCDM", digit) != NULL;
  }
  if (strcmp(flag, "%Zr") == 0) {
    return strchr("01", digit) != NULL;
  }
  *system = (*system < MIN_SYSTEM || *system > MAX_SYSTEM) ? 10 : *system;
  if (*system <= 10) {
    return '0' <= digit && digit <= '0' + *system - 1;
  }
  return ('0' <= digit && digit <= '9') || (toupper(digit) <= 'A' && toupper(digit) <= 'A' + *system - 11);
}


void _parseSpecialValues(const char *flag, const char **_SrcPointer, char *strValue, int *intValue) {
  size_t valueSize = 0;
  int startValue = FALSE;

  while (**_SrcPointer != '\0') {
    if (isspace(**_SrcPointer) && !startValue) {
      ++(*_SrcPointer);
    } else if (_isCorrectSpecialDigit(flag, **_SrcPointer, intValue)) {
      startValue = TRUE;
      strValue[valueSize] = **_SrcPointer;
      ++valueSize;
      strValue[valueSize] = '\0';
      ++(*_SrcPointer);
    } else {
      break;
    }
  }
}


int _processSymbol(const char _FormatSymbol, const char **_SrcPointer) {
  if (isspace(_FormatSymbol)) {
    return 0;
  }
  if (_FormatSymbol == **_SrcPointer) {
    ++(*_SrcPointer);
    return 1;
  }
  return EOF;
}


int _processSpecialFlag(const char *flag, const char **_SrcPointer, va_list args) {
  char strValue[BUFSIZ] = {'\0'};

  if (strcmp(flag, "%Ro") == 0) {
    _parseSpecialValues(flag, _SrcPointer, strValue, NULL);
    if (flagRo(strValue, va_arg(args, int *)) == OK) {
      return 1;
    }
    return EOF;
  }

  if (strcmp(flag, "%Zr") == 0) {
    _parseSpecialValues(flag, _SrcPointer, strValue, NULL);
    strValue[strlen(strValue)] = '\0';
    returnStatus _s = flagZr(strValue, va_arg(args, unsigned int *));
    if (_s == OK) {
      return 1;
    }
    return EOF;
  }
  
  int *number = va_arg(args, int *);
  int system = va_arg(args, int);
  _parseSpecialValues(flag, _SrcPointer, strValue, &system);
  if (flagsCvCV(strValue, &system, isupper(flag[1]), number) == OK) {
    return 1;
  }
  return EOF;
}


int _processDefaultFlag(const char *flag, const char **_SrcPointer, va_list args) {
  int count = 0;
  char format[BUFSIZ] = {'\0'};
  strcat(format, flag);
  strcat(format, "%n");
  
  if (sscanf(*_SrcPointer, format, va_arg(args, long long int *), &count)) {
    *_SrcPointer += count;
    return count;
  }
  return EOF;
}


int _overscanf(const char *_Src, const char *_Format, va_list args) {  
  const char *_SrcPointer = _Src;
  char flag[BUFSIZ];
  size_t i = 0, totalCount = 0;

  while (_Format[i] != '\0' && *_SrcPointer != '\0') {
    if (_Format[i] != '%') {
      if (_processSymbol(_Format[i], &_SrcPointer) != EOF) {
        ++i;  
        continue;
      }
      return EOF;
    } 
    switch (_parseFlag(_Format, i, flag)) {
      case SPECIAL_FLAG:
        if (_processSpecialFlag(flag, &_SrcPointer, args) != EOF) {
          break;
        }
        return EOF;
      case DEFAULT_FLAG:
        if (_processDefaultFlag(flag, &_SrcPointer, args) != EOF) {
          break;
        }
        return EOF;
      default:
        return EOF;
    }
    i += strlen(flag);
    ++totalCount;
  }

  return totalCount;
}


returnStatus _readFile(FILE *_File, _string *string) {
  char symbol;
  while ((symbol = fgetc(_File)) != EOF) {
    if (_stringPushCh(string, symbol) != OK) {
      return INVALID_GET_MEMORY;
    }
  }
  return OK;
}


int overfscanf(FILE *_File, const char *_Format, ...) {
  if (_File == NULL || _Format == NULL) {
    return EOF;
  }
  
  _string string;
  if (_stringInit(&string) != OK) {
    return EOF;
  }

  if (_readFile(_File, &string) != OK) {
    return EOF;  
  }

  va_list args;
  va_start(args, _Format);

  const int count = _overscanf(string.str, _Format, args);
  
  va_end(args);
  free(string.str);

  return count;
}


int oversscanf(const char *_Src, const char *_Format, ...) {
  if (_Src == NULL || _Format == NULL) {
    return EOF;
  }

  va_list args;
  va_start(args, _Format);

  const int count = _overscanf(_Src, _Format, args);

  va_end(args);

  return count;
}
