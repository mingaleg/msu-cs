#include<math.h>
#include<stdio.h>

#include "test.h"
#include "lab01.h"

double test_root_left_1(double x) {
    return x*x*x - 2*x;
}
double test_root_left_1_d(double x) {
    return 3*x*x - 2;
}

double test_root_left_2(double x) {
    return -1/x + 1;
}
double test_root_left_2_d(double x) {
    return 1 / (x*x);
}

double test_root_right_1(double x) {
    return -pow(2, -x) - 2*x;
}
double test_root_right_1_d(double x) {
    return pow(2, -x) * log(2) - 2;
}

double test_root_right_2(double x) {
    return x*x*x - x;
}
double test_root_right_2_d(double x) {
    return 3*x*x - 1;
}

double zero(double x) {
    return 0;
}

const int ROOT_TEST_COUNT = 4;
double (*root_tests_funcs[][2])(double) = {
    {test_root_left_1, test_root_left_1_d},
    {test_root_left_2, test_root_left_2_d},
    {test_root_right_1, test_root_right_1_d},
    {test_root_right_2, test_root_right_2_d}
};
double root_tests_segs[][2] = {
    {-1.5, -1},
    {.5  , 2 },
    {-1.5, 0 },
    {0.8 , 2 }
};
char* root_tests_str[] = {
    "x^3-2x",
    "1-1/x",
    "-2x-2^(-x)",
    "x^3-x",
};

double test_integral_1(double x) {
    return x*x;
}

double test_integral_2(double x) {
    return 1/x;
}

double test_integral_3(double x) {
    return sqrt(1 - x*x);
}

int INTEGRAL_TEST_COUNT = 3;

char* integral_tests_str[] = {
    "x^2",
    "1/x",
    "sqrt(1-x^2)"
};

double (*integral_tests_funcs[])(double) = {
    test_integral_1,
    test_integral_2,
    test_integral_3
};

double integral_tests_segs[][2] = {
    {0 , 9},
    {1 , 2.718281},
    {-1, 1}
};

double integral_tests_ans[] = {
   243,
   1,
   1.570796,
};


int run_tests(void) {
    printf("=== Self-testing ===\n");
    printf("== Testing root() ==\n");
    double eps_root = 1e-5;
    int failed = 0;
    for (int test = 0; test < ROOT_TEST_COUNT; ++test) {
        double r = root(
                root_tests_funcs[test][0], root_tests_funcs[test][1],
                zero, zero,
                root_tests_segs[test][0], root_tests_segs[test][1],
                1e-5
        );
        double v = (*root_tests_funcs[test][0])(r);
        printf("%d. [%s] x = %f f(x) = %f ",
                test+1, root_tests_str[test], r, v
        );
        if (fabs(v) < eps_root) {
            printf("[OK]\n");
        } else {
            printf("[FAIL]\n");
            failed = 1;
        }
    }

    double eps_int = 1e-5;
    printf("== Testing integral() ==\n");
    for (int test = 0; test < INTEGRAL_TEST_COUNT; ++test) {
        float r = integral(
            integral_tests_funcs[test],
            integral_tests_segs[test][0], integral_tests_segs[test][1],
            1e-5
        );
        printf("%d. [%s] [%f;%f] I=%f true=%f ",
                test+1, integral_tests_str[test], 
                integral_tests_segs[test][0], integral_tests_segs[test][1],
                r, integral_tests_ans[test]
        );
        if (fabs(r-integral_tests_ans[test]) < eps_int) {
            printf("[OK]\n");
        } else {
            printf("[FAIL]\n");
            failed = 1;
        }
    }

    if (!failed) {
        printf("=!= All tests are OK =!=\n");
        return 0;
    } else {
        printf("!!! Some tests failed !!!\n");
        return 1;
    }
}
