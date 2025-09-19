#ifndef UTILITIES_H
#define UTILITIES_H

typedef enum {
  OK,
  USAGE_HELP,
  INVALID_ARGUMENT,
  INVALID_COUNT_OF_ARGUMENTS
} return_status;

// Вывод сообщения о работе программы
return_status help();

// Вывод сообщения о некорректном количестве введённых агрументов и завершение работы программы
return_status error_invalid_count_of_arguments();

// Валидация количества аргументов
return_status validate_arguments_count(int argc, char* argv[]);

// Преобразование всех вещественных параметров флага
void convert_all_double_numbers(int argc, char* argv[], double numbers[]); 

#endif
