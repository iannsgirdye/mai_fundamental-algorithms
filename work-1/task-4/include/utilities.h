#ifndef UTILITIES_H
#define UTILITIES_H


#define MAX_N 1e7
#define MAX_N_FOR_FACTORIAL 20
#define EPSILON 1e-7


#include <stdbool.h>


unsigned long long factorial(const int n);
double _middleValue(const double leftValue, const double rightValue);
double _combinations(const int k, const int m);

bool _typeIsExponent(const char *type);
bool _typeIsPi(const char *type);
bool _typeIsLn2(const char *type);
bool _typeIsSqrt2(const char *type);
bool _typeIsGamma(const char *type);


#endif
