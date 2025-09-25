#include "../include/options.h"
#include "../include/colors.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


returnStatus optionD(char inputFileName[], char outputFileName[]) {
  FILE* inputFile = fopen(inputFileName, "r");
  if (checkFileOpening(inputFile, "входной") != OK) {
    return INVALID_FILE;
  }

  FILE* outputFile;
  if (openOutputFile(&outputFile, outputFileName) != OK) {
    return INVALID_FILE;
  }

  char symbol;
  while ((symbol = fgetc(inputFile)) != EOF) {
    if (!isdigit(symbol)) {
      fputc(symbol, outputFile);
    }
  }

  fclose(inputFile);
  if (strlen(outputFileName) > 0) {
    fclose(outputFile);
  }

  printf("\n");
  return OK;
}
