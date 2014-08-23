#ifndef LAB01_H
#define LAB01_H

double root(
        double (*f)(double),  // Function f
        double (*f1)(double), // Derivative f
        double (*g)(double),  // Function g
        double (*g1)(double), // Derivative g
        double a, double b,   // Segment with root
        double eps            // Precision
);

double integral(
    // Calc definite integral
        double (*f)(double), // Function
        double a, double b,  // Segment
        double eps           // Precision
);

#endif
