#ifndef FLAGS_H
#define FLAGS_H


#include "./returnStatus.h"


// Вычислить целое число типа `int`, записанное римскими цифрами
returnStatus flagRo(const char *str, int *_result);


/* 
Вычислить цекендорфово представление целого числа типа `unsigned int`
(коэффициенты `0` и `1` при числах Фибоначчи должны быть записаны 
от младшего к старшему слеванаправо с дополнительной единицей
в конце записи, репрезентирующей окончание записи)
*/
void flagZr(unsigned int number, char *zeckendorf);


#endif
