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
  closeOutputFile(outputFile);

  return OK;
}


returnStatus optionI(char inputFileName[], char outputFileName[]) {
  FILE* inputFile = fopen(inputFileName, "r");
  if (checkFileOpening(inputFile, "входной") != OK) {
    return INVALID_FILE;
  }

  FILE* outputFile;
  if (openOutputFile(&outputFile, outputFileName) != OK) {
    return INVALID_FILE;
  }

  char symbol;
  int countOfAlpha = 0;
  while ((symbol = fgetc(inputFile)) != EOF) {
    if (symbol == '\n') {
      fputc(countOfAlpha + '0', outputFile);
      fputc('\n', outputFile);
      countOfAlpha = 0;
    } else if (isalpha(symbol)) {
      countOfAlpha++;
    }
  }

  if (symbol != '\n') {
    fputc(countOfAlpha + '0', outputFile);
  }

  fclose(inputFile);
  closeOutputFile(outputFile);
  
  return OK;
}


returnStatus optionS(char inputFileName[], char outputFileName[]) {
  FILE* inputFile = fopen(inputFileName, "r");
  if (checkFileOpening(inputFile, "входной") != OK) {
    return INVALID_FILE;
  }

  FILE* outputFile;
  if (openOutputFile(&outputFile, outputFileName) != OK) {
    return INVALID_FILE;
  }

  char symbol;
  int countOfNecessarySymbols = 0;
  while ((symbol = fgetc(inputFile)) != EOF) {
    if (symbol == '\n') {
      fputc(countOfNecessarySymbols + '0', outputFile);
      fputc('\n', outputFile);
      countOfNecessarySymbols = 0;
    } else if (!isalpha(symbol) && !isdigit(symbol) && !isspace(symbol)) {
      countOfNecessarySymbols++;
    }
  }

  if (symbol != '\n') {
    fputc(countOfNecessarySymbols + '0', outputFile);
  }

  fclose(inputFile);
  closeOutputFile(outputFile);

  return OK;
}


returnStatus optionA(char inputFileName[], char outputFileName[]) {
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
    if (isdigit(symbol)) {
      fputc(symbol, outputFile);
    } else {
      fprintf(outputFile, "%X", symbol);
    }
  }

  fclose(inputFile);
  closeOutputFile(outputFile);

  return OK;
}
