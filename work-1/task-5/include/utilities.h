#ifndef UTILITIES_H
#define UTILITIES_H


#include <stdbool.h>


typedef enum {
  OK,
  INVALID_COUNT_OF_ARGUMENTS,
  INVALID_ARGUMENT
} returnStatus;


returnStatus validateCountOfArguments(int argc, char* argv[]);
returnStatus validateFlag(const char flag[], char* mode, bool* haveOutputFile);


#endif
