#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdlib.h>

// Найти первое вхождения символа `c` (беззнаковый тип) в первых `n` байтах строки, на которую указывает аргумент `str`
void *memchr(const void *str, int c, size_t n);

// Сравнить первые `n` байтов `str1` и `str2`
int memcmp(const void *str1, const void *str2, size_t n);

// Скопировать `n` символов из `src` в `dest`
void *memcpy(void *dest, const void *src, size_t n);

// Скопировать символ `c` (беззнаковый тип) в первые `n` символов строки, на которую указывает аргумент `str`
void *memset(void *str, int c, size_t n);

// Добавить строку, на которую указывает `src`, в конец строки, на которую указывает `dest`, длиной до `n` символов
char *strncat(char *dest, const char *src, size_t n);

// Найти первое вхождения символа `c` (беззнаковый тип) в строке, на которую указывает аргумент `str`
char *strchr(const char *str, int c);

// Сравнить не более первых `n` байтов `str1` и `str2`
int strncmp(const char *str1, const char *str2, size_t n);

// Скопировать до `n` символов из строки, на которую указывает `src`, в `dest`
char *strncpy(char *dest, const char *src, size_t n);

// Вычислить длину начального сегмента `str1`, который полностью состоит из символов, не входящих в `str2`
size_t strcspn(const char *str1, const char *str2);

// Найти во внутреннем массиве номер ошибки `errnum` и вернуть указатель на строку с сообщением об ошибке
char *strerror(int errnum);

// Вычислить длину строки `str`, не включая завершающий нулевой символ
size_t strlen(const char *str);

// Найти первый символ в строке `str1`, который соответствует любому символу, указанному в `str2`
char *strpbrk(const char *str1, const char *str2);

// Найти последнее вхождения символа `c` (беззнаковый тип) в строке, на которую указывает аргумент `str`
char *strrchr(const char *str, int c);

// Найти первое вхождение всей строки `needle` (не включая завершающий нулевой символ), которая появляется в строке `haystack`
char *strstr(const char *haystack, const char *needle);

// Разбить строку `str` на ряд токенов, разделенных `delim`
char *strtok(char *str, const char *delim);


#endif
