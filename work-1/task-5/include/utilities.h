#ifndef UTILITIES_H
#define UTILITIES_H


#include <stdbool.h>
#include <stdio.h>


typedef enum {
  OK,
  INVALID_COUNT_OF_ARGUMENTS,
  INVALID_ARGUMENT,
  MEMORY_ERROR,
  INVALID_FILE
} returnStatus;


returnStatus validateCountOfArguments(int argc, char* argv[]);
returnStatus validateFlag(const char flag[], char* mode, bool* haveOutputFile);
returnStatus defineOutputFileName(char** outputFileName, int argc, char* argv[]);
returnStatus checkFileOpening(const FILE* file, const char fileType[]);
returnStatus openOutputFile(FILE** outputFileg, const char outputFileName[]);


#endif
