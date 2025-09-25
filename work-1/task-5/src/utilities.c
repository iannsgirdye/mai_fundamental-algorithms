#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


returnStatus validateCountOfArguments(int argc, char* argv[]) {
  if (argc < 2 || argc > 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE " введено некорректное количество аргументов. "
      "(справка: флаг \"-h\")."
    );
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  if (argv[1][1] == 'n' && argc == 2) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE " введено некорректное количество аргументов "
      "(справка: флаг \"-h\")."
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
      COLOR_WHITE "флаг не введён."
    );
    return INVALID_ARGUMENT;
  }

  if (flagLen < 2 || flagLen > 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE "флаг введён в некорректном формате."
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
        COLOR_WHITE "введён несуществующий флаг"
      );
      return INVALID_ARGUMENT;
  }
}
