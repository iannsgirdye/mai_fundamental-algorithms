#include "../include/utilities.h"
#include "../include/colors.h"
#include "../include/errors.h"
#include <stdio.h>
#include <limits.h>


returnStatus _errorInvalidFile(const char fileType[]) {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "не удалось открыть %s файл.\n",
    fileType
  );
  return INVALID_FILE;
}


returnStatus _errorInvalidDataInFile() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "в файле должны быть только латинские буквы, цифры и пробельные символы.\n"
  );
  return INVALID_DATA_IN_FILE;
}


returnStatus _errorIntOverflow() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "файл содержит число, которое выходит за отрезок [%d; %d].\n",
    INT_MIN, INT_MAX
  );
  return INVALID_DATA_IN_FILE;
}
