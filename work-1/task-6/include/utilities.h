#ifndef UTILITIES_H
#define UTILITIES_H


typedef enum {
  OK,
  HELP_USAGE,
  INVALID_COUNT_OF_ARGUMENTS,
  INVALID_ARGUMENT
} returnStatus;


void help();
returnStatus validateCountOfArguments(int argc);
returnStatus validateSecondArgument(char* argv[], double* epsilon);


#endif
