#ifndef UTILITIES_H
#define UTILITIES_H

typedef enum {
  OK,
  USAGE_HELP,
  INCORRECT_ARGUMENTS_COUNT,
  INCORRECT_ARGUMENT_VALUE
} return_status;

// Проверка количества аргументов, вывод информации о программе при необходимости
return_status validate_arguments_count(const int argc, char* argv[]);

// Валидация и определение числа x
return_status validate_x(const char *str_x, int* x);

// Валидация и определение флага
return_status validate_flag(const char *str_flag, char* flag);

#endif
