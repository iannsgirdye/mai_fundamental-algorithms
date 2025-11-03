#ifndef FLAGS_H
#define FLAGS_H


#include "./returnStatus.h"


// Записать целое число типа `int` римскими цифрами
returnStatus flagRo(const int number, char *strRomanNumeral);


/* 
Вычислить цекендорфово представление целого числа типа `unsigned int`
(коэффициенты `0` и `1` при числах Фибоначчи должны быть записаны 
от младшего к старшему слеванаправо с дополнительной единицей
в конце записи, репрезентирующей окончание записи)
*/
returnStatus flagZr(unsigned int number, char *zeckendorf);


#endif
