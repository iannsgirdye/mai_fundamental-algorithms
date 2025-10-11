#ifndef CALCULATE_H
#define CALCULATE_H


double limit(double (*function)(const int), const double epsilon);
double sqrt2Limit(double (*function)(const double), const double epsilon);

double row(const char *type, double (*function)(const int), const double epsilon);
double product(const char *type, double (*function)(const int), const double epsilon);

double equation(const char *type, double (*function)(const double), const double epsilon);
double equationLn2(double (*function)(const double, const double), const double exponent, const double epsilon);


#endif
