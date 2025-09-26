#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void printHelp() {
  printf(
    "Формат команды: <программа> <флаг> <путь к входному файлу> [путь к выходному файлу]\n"
    "Формат флага: \"-h\" или \"/h\"\n\n"
    "-h    Вывести справочную информацию о программе.\n\n"
    "-d    Исключить символы арабских цифр из входного файла.\n\n"
    "-i    Для каждой строки входного файла в выходной файл записать\n"
    "      сколько раз в этой строке встречаются символы букв латинского алфавита.\n\n"
    "-s    Для каждой строки входного файла в выходной файл записать\n"
    "      сколько раз в этой строке встречаются символы, отличные от символов\n"
    "      букв латинского алфавита, символов арабских цифр и символа пробела.\n\n"
    "-a    Заменить символы, отличные от символов цифр, ASCII кодом,\n"
    "      записанным в системе счисления с основанием 16.\n"
  );
}


returnStatus validateCountOfArguments(int argc, char* argv[]) {
  if (argc == 2 && (argv[1][0] == '/' || argv[1][0] == '-') && argv[1][1] == 'h') {
    printHelp();
    return HELP_USAGE;
  }

  if (argc < 3 || argc > 4) {
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


size_t _defineIndexOfBeginOfFileName(const char fileName[]) {
  size_t indexOfBeginOfFileName = 0;
  for (size_t i = 0; fileName[i] != '\0'; ++i) {
    if (fileName[i] == '\\' || fileName[i] == '/') {
      indexOfBeginOfFileName = i + 1;
    }
  }
  return indexOfBeginOfFileName;
}


returnStatus defineOutputFileName(char** outputFileName, int argc, char* argv[]) {
  switch (argc) {
    case 4:
      *outputFileName = argv[3];
      return OK;
    case 3:
      const char* inputFileName = argv[2];
      const char* beginOfOutputFileName = "out_";
      size_t sizeOfBeginOfOutputFileName = strlen(beginOfOutputFileName);
      size_t sizeOfOutputFileName = sizeOfBeginOfOutputFileName + strlen(inputFileName);
      char* tmpOutputFileName = (char*)malloc(sizeOfOutputFileName);

      if (tmpOutputFileName == NULL) {
        printf(
          COLOR_BOLD_RED "Ошибка: "
          COLOR_WHITE "не удалось выделить память при формировании имени выходного файла.\n");
        return MEMORY_ERROR;
      }

      size_t indexOfBeginOfInputFileName = _defineIndexOfBeginOfFileName(inputFileName);
      strncpy(tmpOutputFileName, inputFileName, indexOfBeginOfInputFileName);
      strcat(tmpOutputFileName, beginOfOutputFileName);
      for (size_t i = indexOfBeginOfInputFileName; inputFileName[i] != '\0'; ++i) {
        tmpOutputFileName[i + sizeOfBeginOfOutputFileName] = inputFileName[i];
      }
      
      tmpOutputFileName[sizeOfOutputFileName] = '\0';
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
