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
  char strCountOfAlpha[11];
  while ((symbol = fgetc(inputFile)) != EOF) {
    if (symbol == '\n') {
      sprintf(strCountOfAlpha, "%d", countOfAlpha);
      fprintf(outputFile, "%s\n", strCountOfAlpha);
      countOfAlpha = 0;
    } else if (isalpha(symbol)) {
      countOfAlpha++;
    }
  }

  if (symbol != '\n') {
    sprintf(strCountOfAlpha, "%d", countOfAlpha);
    fprintf(outputFile, "%s", strCountOfAlpha);
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
  char strCountOfNecessarySymbols[11];
  while ((symbol = fgetc(inputFile)) != EOF) {
    if (symbol == '\n') {
      sprintf(strCountOfNecessarySymbols, "%d", countOfNecessarySymbols);
      fprintf(outputFile, "%s\n", strCountOfNecessarySymbols);
      countOfNecessarySymbols = 0;
    } else if (!isalpha(symbol) && !isdigit(symbol) && !isspace(symbol)) {
      countOfNecessarySymbols++;
    }
  }

  if (symbol != '\n') {
    sprintf(strCountOfNecessarySymbols, "%d", countOfNecessarySymbols);
    fprintf(outputFile, "%s", strCountOfNecessarySymbols);
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
