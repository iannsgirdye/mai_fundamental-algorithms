#include "../include/errors.h"
#include "../include/colors.h"
#include <limits.h>


returnStatus _errorInvalidArray(const char *functionName) {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "invalid array as argument in %s.\n", functionName);
  return INVALID_ARRAY;
}


returnStatus _errorSystemIsNotDecimalNumber(const char *text) {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "\"%s\" is not a decimal number.\n", text);
  return SYSTEM_IS_NOT_DECIMAL_NUMBER;
}


returnStatus _errorInvalidSystem() {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "system is not in range [0; %d].\n", INT_MAX);
  return INVALID_SYSTEM;
}


returnStatus _errorInvalidValue(const double value) {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "%lf is invalid value for decimal.\n", value);
  return INVALID_VALUE;
}
