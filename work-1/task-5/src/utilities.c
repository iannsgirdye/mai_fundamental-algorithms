#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


returnStatus validateCountOfArguments(int argc, char* argv[]) {
  if (argc < 2 || argc > 4) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "введено некорректное количество аргументов "
      "(справка: флаг \"-h\").\n"
    );
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  if (argv[1][1] == 'n' && strlen(argv[1]) == 3 && argc < 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "введено некорректное количество аргументов "
      "(справка: флаг \"-h\").\n"
    );
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  return OK;
}


returnStatus validateFlag(const char flag[], char* mode, bool* haveOutputFile) {
  size_t flagLen = strlen(flag);

  if (flag[0] != '-' && flag[0] != '/') {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "флаг не введён.\n"
    );
    return INVALID_ARGUMENT;
  }

  if (flagLen < 2 || flagLen > 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "флаг введён в некорректном формате.\n"
    );
    return INVALID_ARGUMENT;
  }

  *haveOutputFile = (flag[1] == 'n') ? true : false;

  char modeLetter = flag[flagLen - 1];
  switch (modeLetter) {
    case 'd':
    case 'i':
    case 's':
    case 'a':
      *mode = modeLetter;
      return OK;
    default:
      printf(
        COLOR_BOLD_RED "Ошибка: "
        COLOR_WHITE "введён несуществующий флаг.\n"
      );
      return INVALID_ARGUMENT;
  }

  return OK;
}


returnStatus defineOutputFileName(char** outputFileName, int argc, char* argv[]) {
  switch (argc) {
    case 4:
      *outputFileName = argv[3];
      return OK;
    case 3:
      const char* beginOutputFileName = "out_";
      char* tmpOutputFileName = (char*)malloc(strlen(beginOutputFileName) + strlen(argv[2]));
      if (tmpOutputFileName == NULL) {
        printf(
          COLOR_BOLD_RED "Ошибка: "
          COLOR_WHITE "не удалось выделить память при формировании имени выходного файла.\n");
        return MEMORY_ERROR;
      }
      strcpy(tmpOutputFileName, beginOutputFileName);
      strcat(tmpOutputFileName, argv[2]);
      *outputFileName = tmpOutputFileName;
      return OK;
    default:
      return OK;
  }
}


returnStatus checkFileOpening(const FILE* file, const char fileType[]) {
  if (file == NULL) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "не удалось открыть %s файл.\n",
      fileType
    );
    return INVALID_FILE;
  }

  return OK;
}


returnStatus openOutputFile(FILE** outputFile, const char outputFileName[]) {
  if (strlen(outputFileName) > 0) {
    *outputFile = fopen(outputFileName, "w");
    if (checkFileOpening(*outputFile, "выходной") != OK) {
      return INVALID_FILE;
    }
  } else {
    *outputFile = stdout;
  }

  return OK;
}


returnStatus closeOutputFile(FILE* outputFile) {
  if (outputFile != stdout) {
    fclose(outputFile);
  } else {
    printf("\n");
  }

  return OK;
}
