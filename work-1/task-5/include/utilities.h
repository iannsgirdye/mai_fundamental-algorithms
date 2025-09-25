#ifndef UTILITIES_H
#define UTILITIES_H


typedef enum {
  OK,
  INVALID_COUNT_OF_ARGUMENTS,
  INVALID_ARGUMENT
} returnStatus;


returnStatus validateCountOfArguments(int argc, char* argv[]);


#endif
