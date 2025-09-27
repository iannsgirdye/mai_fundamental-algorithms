#include "../include/utilities.h"
#include "../include/options.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char* argv[]) {
  if (validateCountOfArguments(argc, argv) != OK) {
    return 0;
  }

  char mode;
  bool haveOutputFile;
  if (validateFlag(argv[1], &mode, &haveOutputFile) != OK) {
    return 0;
  }

  char* inputFileName = argv[2];
  char* outputFileName = "";
  if (haveOutputFile) {
    defineOutputFileName(&outputFileName, argc, argv);
  }

  switch (mode) {
    case 'd':
      optionD(inputFileName, outputFileName);
      break;
    case 'i':
      optionI(inputFileName, outputFileName);
      break;
    case 's':
      optionS(inputFileName, outputFileName);
      break;
    case 'a':
      optionA(inputFileName, outputFileName);
      break;
  }

  /* строка outputFileName хранится в динамической памяти,
  которая выделяется в функции defineOutputFileName */
  if (strlen(outputFileName) > 0) {
    free(outputFileName);
  }

  return 0;
}
