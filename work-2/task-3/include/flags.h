#ifndef FLAGS_H
#define FLAGS_H


#include "./returnStatus.h"


// Записать целое число типа `int` римскими цифрами
returnStatus flagRo(const int number, char *strRomanNumeral);


/* 
Записать целое число типа типа `unsigned int` в цекендорфовом представлении
(коэффициенты `0` и `1` при числах Фибоначчи должны быть записаны 
от младшего к старшему слеванаправо с дополнительной единицей
в конце записи, репрезентирующей окончание записи)
*/
returnStatus flagZr(unsigned int number, char *zeckendorf);


/*
Записать в `*numberInSystem` целое число типа `int` (`number`) 
в системе счисления `*system` (в диапазоне `[2..36]`, иначе устанавливается равной `10`).
Параметр `isCapitalize` равен `1`, если в `numberInSystem` символы букв записаны
в верхнем регистре, иначе — `0`
*/
returnStatus flagsCvCV(int number, int *system, const int isCapitalize, char *numberInSystem);


/*
Записать в `*number` целое число типа `int` на основе его строкового представления `numberInSystem`
в системе счисления `*system` (в диапазоне `[2..36]`, иначе устанавливается равной `10`).
Параметр `isCapitalize` равен `1`, если в `numberInSystem` символы букв записаны
в верхнем регистре, иначе — `0`
*/
returnStatus flagsToTO(const char *numberInSystem, int *system, const int isCapitalize, int *number);


#endif
