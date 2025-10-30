#include "../include/errors.h"
#include "../include/colors.h"


returnStatus _errorInvalidArray() {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "invalid array.\n");
  return INVALID_ARRAY;
}


returnStatus _errorInvalidSystem() {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "invalid system.\n");
  return INVALID_SYSTEM;
}


returnStatus _errorInvalidValue() {
  printf(COLOR_BOLD_RED "Error: " COLOR_WHITE "invalid value of fraction.\n");
  return INVALID_VALUE;
}
