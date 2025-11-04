#ifndef FLAGS_H
#define FLAGS_H


#include "./returnStatus.h"


// Записать в `romanNumeral` римскими цифрами целое число типа `int` (`number`)
returnStatus flagRo(const int number, char *strRomanNumeral);


/* 
Записать в `zeckendorf` целое число типа `unsigned int` (`number`) 
в цекендорфовом представлении (коэффициенты `0` и `1` при числах Фибоначчи
записываются от младшего к старшему слева направо с дополнительной единицей
в конце записи, репрезентирующей её окончание)
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
