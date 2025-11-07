#ifndef FLAGS_H
#define FLAGS_H


#include "./returnStatus.h"


// Записать в `*number` целое число типа `int` на основе его представления римскими цифрами `romanNumeral`
returnStatus flagRo(const char *romanNumeral, int *number);


/* 
Записать в `*number` целое число типа `unsigned int` на основе его цекендорфова представления `zeckendorf`
(коэффициенты `0` и `1` при числах Фибоначчи записываются от младшего к старшему
слева направо с дополнительной единицей в конце записи, репрезентирующей её окончание)
*/
returnStatus flagZr(const char *zeckendorf, unsigned int *number);


/*
Записать в `*number` целое число типа `int` на основе его представления
в системе счисления `*system` (в диапазоне `[2..36]`, иначе устанавливается равной `10`).
Параметр `isCapitalize` передаётся равным `1`, если в `numberInSystem` 
символы букв записаны в верхнем регистре, иначе — `0`
*/
returnStatus flagsCvCV(const char *numberInSystem, int *system, const int isCapitalize, int *number);


#endif
