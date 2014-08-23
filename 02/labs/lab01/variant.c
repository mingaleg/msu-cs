#include "variant.h"

/* ===== Functions to research  ===== */

double f1(double x) {
    return .6*x+3;
}
double f1_d(double x) {
    return .6;
}

double f2(double x) {
    return (x-2)*(x-2)*(x-2) - 1;
}
double f2_d(double x) {
    return 3*(x-2)*(x-2);
}

double f3(double x) {
    return 3 / x;
}
double f3_d(double x) {
    return -3 / (x*x);
}

double (*funcs[3][2])(double) = {
    {f1, f1_d},
    {f2, f2_d},
    {f3, f3_d}
};

double segs[3][3][2] = {
    { {0 , 0}, {3 , 4}, {.5, 1} },
    { {3 , 4}, {0 , 0}, {3 , 4} },
    { {.5, 1}, {3 , 4}, {0 , 0} }
};

/* ================================ */
