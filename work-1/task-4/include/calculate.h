#ifndef CALCULATE_H
#define CALCULATE_H


double limit(double (*function)(const int), const double epsilon);
double sqrt2Limit(double (*function)(const double), const double epsilon);
double row(double (*function)(const int), const int startN, const double epsilon);
double product(double (*function)(const int), const int startN, const double epsilon);


#endif
