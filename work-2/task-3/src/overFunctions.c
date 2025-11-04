#include "../include/overFunctions.h"
#include "../include/flags.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>


#define STRING_START_CAPACITY 32
#define RESULT_CAPACITY       64
#define FLAG_CAPACITY          8


typedef enum {
  Ro,
  Zr,
  Cv,
  CV,
  to,
  TO,
  mi,
  mu,
  md,
  mf
} idSpecialFlags;


typedef struct {
  char *str;
  size_t size;
  size_t capacity;
} _string;


int _stringIsFull(_string *string) {
  return string->size == string->capacity;
}


int _stringWillOverflow(_string *string, const char *substring) {
  return strlen(substring) + string->size > string->capacity;
}


returnStatus reallocStr(_string *string) {
  string->capacity *= 2;
  char *tmpStr = (char *)realloc(string->str, string->capacity);
  if (tmpStr == NULL) {
    free(string->str);
    return INVALID_GET_MEMORY;
  }
  string->str = tmpStr;
  return OK;
}


int _isDefaultFlag(const char letter) {
  const char specialFlagsFirstLetters[6] = {'R', 'Z', 'C', 't', 'T', 'm'};
  for (size_t i = 0; i != 6; ++i) {
    if (letter == specialFlagsFirstLetters[i]) {
      return 0;
    }
  }
  return 1;
}


void _defineFlag(const char *_Format, const size_t i, char *flag, int isSpecialFlag) {
  flag[0] = '%', flag[1] = '\0';
  size_t len = 1;

  if (isSpecialFlag) {
    len = 3;  
  } else {
    switch (_Format[i + 1]) {
      case 'z':
        len = 4;
        break;
      case 'h':
      case 'l':
        len = (_Format[i + 1] == _Format[i + 2]) ? 4 : 3;
        break;
      default:
        len = 2;
    }
  }

  strncat(flag, &_Format[i + 1], len);
  flag[len] = '\0';
}


int _idSpecialFlag(const char *flag) {
  int idFlag = -1;
  const char *flags[10] = {"%Ro", "%Zr", "%Cv", "%CV", "%to", "%TO", "%mi", "%mu", "%md", "%mf"};

  for (size_t i = 0; i != 10; ++i) {
    if (strcmp(flags[i], flag) == 0) {
      idFlag = i;
      break;
    }
  }
  return idFlag;
}


returnStatus _parseFlag(const char *_Format, size_t i, char *flag) {
  if (_Format[i + 1] == '%') {
    return PERCENT_FLAG;
  }
  if (isalpha(_Format[i + 1])) {
    if (_isDefaultFlag(_Format[i + 1])) {
      _defineFlag(_Format, i, flag, 0);
      return DEFAULT_FLAG;
    }
    if (isalpha(_Format[i + 2])) {
      _defineFlag(_Format, i, flag, 1);
      return SPECIAL_FLAG;
    }
  }
  return INVALID_FLAG;
}


returnStatus _useSpecialFlag(const char *flag, va_list args, char *result) {
  int intNumber, system;
  unsigned int uIntNumber;
  char *strNumber;
  void *pointer;

  switch (_idSpecialFlag(flag)) {
    case Ro: 
      intNumber = va_arg(args, int);
      return flagRo(intNumber, result);
    case Zr: 
      uIntNumber = va_arg(args, unsigned int);
      return flagZr(uIntNumber, result);
    case Cv: 
      intNumber = va_arg(args, int);
      system = va_arg(args, int);
      return flagsCvCV(intNumber, &system, 0, result);
    case CV:
      intNumber = va_arg(args, int);
      system = va_arg(args, int);
      return flagsCvCV(intNumber, &system, 1, result);
    case to:
      strNumber = va_arg(args, char *);
      system = va_arg(args, int);
      return flagsToTO(strNumber, &system, 0, result);
    case TO:
      strNumber = va_arg(args, char *);
      system = va_arg(args, int);
      return flagsToTO(strNumber, &system, 0, result);
    case mi:
      pointer = va_arg(args, void *);
      return flagsM(pointer, 'i', result);
    case mu:
      pointer = va_arg(args, void *);
      return flagsM(pointer, 'u', result);
    case md:
      pointer = va_arg(args, void *);
      return flagsM(pointer, 'd', result);
    case mf:
      pointer = va_arg(args, void *);
      return flagsM(pointer, 'f', result);
    default:
      return INVALID_FLAG;
  }
}


void _printResult(_string *string, char *result) {
  if (_stringWillOverflow(string, result)) {
    reallocStr(string);
  }

  strcat(string->str, result);
  string->size += strlen(result);
}


returnStatus _makeString(_string *string, const char *_Format, va_list args) {
  char result[RESULT_CAPACITY];
  char flag[FLAG_CAPACITY];
  size_t i = 0;

  while (_Format[i] != '\0') {
    result[0] = '\0';
    if (_Format[i] != '%') {
      sprintf(result, "%c", _Format[i]);
      _printResult(string, result);
      i += 1;
      continue;
    } 
    switch (_parseFlag(_Format, i, flag)) {
      case PERCENT_FLAG:
        sprintf(result, "%c", '%');
        _printResult(string, result);
        i += 2;
        break;
      case DEFAULT_FLAG:
        sprintf(result, flag, va_arg(args, long long int));
        _printResult(string, result);
        i += strlen(flag);
        break;
      case SPECIAL_FLAG:
        _useSpecialFlag(flag, args, result);
        _printResult(string, result);
        i += 3;
        break;
      default:
        string->size = 0;
        return INVALID_FLAG;
    }
  }

  string->str[string->size] = 0;

  return OK;
}


int overfprintf(FILE *_File, const char *_Format, ...) {
  _string string = {.size = 0, .capacity = STRING_START_CAPACITY};
  string.str = (char *)malloc(string.capacity);
  if (string.str == NULL) {
    return string.size;
  }

  va_list args;
  va_start(args, _Format);

  _makeString(&string, _Format, args);
  fputs(string.str, _File);

  va_end(args);
  free(string.str);

  return string.size;
}


int oversprintf(char *_Dest, const char *_Format, ...) {
  _string string = {.size = 0, .capacity = STRING_START_CAPACITY};
  string.str = (char *)malloc(string.capacity);
  if (string.str == NULL) {
    return string.size;
  }

  va_list args;
  va_start(args, _Format);

  _makeString(&string, _Format, args);
  strcpy(_Dest, string.str);

  va_end(args);
  free(string.str);

  return string.size;
}
