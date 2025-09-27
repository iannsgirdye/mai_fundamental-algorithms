#include "../include/errors.h"
#include "../include/utilities.h"
#include "../include/colors.h"
#include <stdio.h>


returnStatus _errorInvalidFormat() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "введено число в некорректном формате (на одной строке: <число> <система счисления>).\n"
  );
  return INVALID_FORMAT;
}


returnStatus _errorInvalidSystem() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "система счисления должна быть в диапозоне [2..36].\n"
  );
  return INVALID_VALUE;
}


returnStatus _errorSmallAlpha() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "в записи числа запрещено использовать строчные буквы.\n"
  );
  return INVALID_VALUE;
}


returnStatus _errorInvalidNumber() {
  printf(
    COLOR_BOLD_RED "Ошибка: "
    COLOR_WHITE "в записи числа есть недопустипые символы.\n"
  );
  return INVALID_VALUE;
}
