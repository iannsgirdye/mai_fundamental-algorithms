#ifndef LIVER_H
#define LIVER_H

typedef struct {
  unsigned int id;       // неизменно в течение работы программы
  char *surname;         // только буквы латинского алфавита
  char *name;            // только буквы латинского алфавита
  char *patronymic;      // только буквы латинского алфавита, допускается пустая строка
  int birthDay;
  int birthMonth;
  int birthYear;
  char sex;              // M = мужской, W = женский
  double averageSalary;  // неотрицательное 
} Liver;

#endif
