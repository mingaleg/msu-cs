#ifndef VARIANT_H
#define VARIANT_H

double f1(double x);
double f1_d(double x);
double f2(double x);
double f2_d(double x);
double f3(double x);
double f3_d(double x);
extern double (*funcs[3][2])(double);
extern double segs[3][3][2];

#endif
