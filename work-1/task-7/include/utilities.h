#ifndef UTILITIES_H
#define UTILITIES_H


typedef enum {
  OK,
  INVALID_COUNT_OF_ARGUMENTS,
  INVALID_FILE,
  INVALID_DATA_IN_FILE
} returnStatus;


returnStatus validateCountOfArguments(const int argc);


#endif
