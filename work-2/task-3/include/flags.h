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
Записать целое число типа `int` в системе счисления с заданным основанием
(при обработке флага первым параметром функции, “снимаемым” со стека, 
является целое число типа `int`, вторым - основание целевой системы счисления
в диапазоне `[2..36]` (при основании системы счисления, не входящем в диапазон,
значение основания системы счисления устанавливается равным `10`))
*/
returnStatus flagsCvCV(int number, int system, char *result, const int isCapitalize);


/*
Записать в `*number` целое число типа `int` на основе его строкового представления `numberInSystem`
в системе счисления `*system` (в диапазоне `[2..36]`, иначе устанавливается равной `10`).
Параметр `isCapitalize` равен `1`, если в `numberInSystem` символы букв записаны
в верхнем регистре, иначе — `0`
*/
returnStatus flagsToTO(const char *numberInSystem, int *system, const int isCapitalize, int *number);


#endif
