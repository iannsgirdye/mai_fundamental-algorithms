#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef enum {
  OK,
  INVALID_ARGUMENT
} return_status;

// Считывание и валидация числа T
return_status get_T(int* T);

// Считывание и валидация порядковый номеров нужных простых чисел
return_status get_order(int order[], int T);

// Поиск простых чисел
void prime_numbers(int order[], int T, int results[]);

// Вывод результатов поиска простых чисел
void print_results(int results[], int T);

#endif
