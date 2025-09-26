#ifndef UTILITIES_H
#define UTILITIES_H


typedef enum {
  OK,
  INVALID_COUNT_OF_ARGUMENTS
} returnStatus;


returnStatus validateCountOfArguments(const int argc);


#endif
