#include "../include/function.h"
#include "../include/errors.h"
#include "../include/utilities.h"
#include <stdlib.h>
#include <math.h>
#include <limits.h>


#define max(a, b) ((a > b) ? a : b)
#define EPSILON 1e-9
#define INFINITY_FRACTION -1
#define MAX_DENOMINATOR_POW 6


int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return max(a, b);
}


bool isEasy(const int number) {
  for (int d = 2; d * d <= number; ++d) {
    if (number % d == 0) {
      return false;
    }
  }
  return true;
}


int _calculateDenominator(const double decimalFraction) {
  double numerator = decimalFraction;
  int denominatorPow = 0;

  while (fabs(numerator - round(numerator)) > EPSILON) {
    numerator *= 10;
    ++denominatorPow;
    if (denominatorPow > MAX_DENOMINATOR_POW) {
      return INFINITY_FRACTION;
    }
  }

  int denominator = pow(10, denominatorPow);
  const int commonDivisor = gcd(round(numerator), denominator);
  denominator /= commonDivisor;
  
  return denominator;
}


bool _badDivider(const int d, const int system) {
  return isEasy(d) && system % d != 0;
}


/* простые делители знаменателя должны быть 
   только среди простых делителей основания системы счисления */
bool _defineFractionFinite(const double decimalFraction, const int system) {
  const int denominator = _calculateDenominator(decimalFraction);
  if (denominator == INFINITY_FRACTION) {
    return false;
  }
  for (int d = 2; d * d <= denominator; ++d) {
    if (denominator % d == 0) {
      if (_badDivider(d, system)) {
        return false;
      }
      if (_badDivider(denominator / d, system)) {
        return false;
      }
    }
  }
  if (isEasy(denominator) && system % denominator != 0) {
    return false;
  }
  return true;
}


returnStatus defineFractionsFinite(const int system, bool results[], const size_t argc, ...) {
  if (checkArray(argc, results) != OK) {
    return _errorInvalidArray("defineFractionsFinite");
  }

  va_list argv;
  va_start(argv, argc);

  double decimalFraction;
  for (size_t i = 0; i != argc; ++i) {
    decimalFraction = va_arg(argv, double);
    results[i] = _defineFractionFinite(decimalFraction, system);
  }

  va_end(argv);

  return OK;
}
