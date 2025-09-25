#include "utilities.h"
#include "colors.h"


returnStatus validateCountOfArguments(int argc, char* argv[]) {
  if (argc < 2 || argc > 3) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE " введено некорректное количество аргументов. "
      "(справка: флаг \"-h\")."
    );
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  if (argv[1][1] == 'n' && argv == 2) {
    printf(
      COLOR_BOLD_RED "Ошибка: "
      COLOR_WHITE " введено некорректное количество аргументов "
      "(справка: флаг \"-h\")."
    );
    return INVALID_COUNT_OF_ARGUMENTS;
  }

  return OK;
}