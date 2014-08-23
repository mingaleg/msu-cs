#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<stdlib.h>

#include "variant.h"
#include "test.h"


double sign(double d) {
    return (1e-6 < d) - (d < -1e-6);
}

double root(
    // Solve f(x) = g(x)
        double (*f)(double),  // Function f
        double (*f1)(double), // Derivative f
        double (*g)(double),  // Function g
        double (*g1)(double), // Derivative g
        double a, double b,   // Segment with root
        double eps            // Precision
){
    int right = (f(a)-g(a) < 0) ^ 
        ((f((a+b)/2) - g((a+b)/2)) * 2 > (f(a)-g(a) + f(b)-g(b)));
    double x;
    if (right) {
        x = b;
        eps *= -1;
    } else {
        x = a;
    }
    while (sign(f(x)-g(x))*sign(f(x+eps)-g(x+eps)) > 0) { 
        x = x - (f(x)-g(x)) / (f1(x)-g1(x));
    }
    return x;
}

double integral(
    // Calc definite integral
        double (*f)(double), // Function
        double a, double b,  // Segment
        double eps           // Precision
){
    int n = 32;
    double h = (b-a)/n;
    double I = .5*f(a) + .5*f(b);
    for (int i = 1; i < n; ++i) {
        I += f(a+i*h);
    }

    double I0, h0, n0;

    int COUNT = 1;

    do {
        COUNT += 1;
        I0 = I; h0 = h; n0 = n;
        n = n0*2;
        h = (b-a)/n;
        for (int i = 1; i < n; i+=2) {
            I += f(a+i*h);
        }
    } while (fabs(I*h-I0*h0) >= eps/3);
    return I*h;
}


double roots[3][3];
int print_roots = 0;

int find_roots(void) {
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 3; ++j) {
            if (print_roots) printf("(%d, %d): ", i+1, j+1);
            double x = root(funcs[i][0], funcs[i][1],
                            funcs[j][0], funcs[j][1],
                            segs[i][j][0], segs[i][j][1],
                            0.00001
                        );
            roots[i][j] = x;
            roots[j][i] = x;
            if (print_roots) printf("x = %f, f%d(%f) = %f, f%d(%f) = %f\n", 
                    x, i+1, x, (*funcs[i][0])(x), 
                    j+1, x, (*funcs[j][0])(x)
            );
        }
    }
}

double calculate_area(void) {
    double ans = 0;
    ans += integral(funcs[0][0], roots[0][1], roots[0][2], 1e-5);
    ans += integral(funcs[1][0], roots[1][2], roots[1][0], 1e-5);
    ans += integral(funcs[2][0], roots[2][0], roots[2][1], 1e-5);
    return fabs(ans);
}

void help(void) {
    printf("lab01 v0.1.0, Mingalev Oleg 2014\n");
    printf("Usage: lab01 [-h] [-t] [-r] [-v]\n\n");
    printf("Options:\n");
    printf(" -h: Show this help\n");
    printf(" -t: Run tests\n");
    printf(" -r: Print roots\n");
    //printf(" -v: Variant info\n");
    exit(0);
}

void variant_info(void){
    printf("lab01 v0.1.0, Mingalev Oleg 2014\n\n");
    printf("Use lab01 -h to see help page\n\n");
    printf("Variant: 6-3-2\n\n");
    printf("Functions:\n");
    printf(" 0.6x+3\n");
    printf(" (x-2)^3-1\n");
    printf(" 3/x\n\n");
    printf("Root approximation method: Newton's method\n");
    printf("Definite integral approximation method: Trapezoidal rule\n");
    printf("========================================================\n\n");
}

int main(int argc, char *argv[]) {
    int cur = 0;
    variant_info();
    while ((cur = getopt(argc, argv, "hrtv")) != -1) {
        switch (cur) {
            case 'h': case '?': help(); break;
            //case 'v': variant_info(); break;
            case 't': exit(run_tests()); break;
            case 'r': print_roots = 1; break;
        }
    }
    find_roots();
    double ans = calculate_area();
    printf("Area: %f\n", ans);
    return 0;
}
