#include<stdio.h>
#include<math.h>

#define eps 1e-6

double throw_a_brick(double a, double b, double w) {
    if (a - eps <= w) return b;
    double alpha = acos(w / sqrt(a*a + b*b)) + acos(a / sqrt(a*a + b*b));
    double h = fabs(b*cos(alpha) + a*sin(alpha));
    return h;
}

int can_throw(double a, double b, double w) {
    if (a > b) {
        double tmp = a; a = b; b = tmp;
    }
    return (a - eps <= w);
}

int main(void) {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    if (can_throw(c, d, a) && (throw_a_brick(c, d, a) - eps <= b)) {
        printf("YES\n");
        return 0;
    }
    if (can_throw(d, c, a) && (throw_a_brick(d, c, a) - eps <= b)) {
        printf("YES\n");
        return 0;
    }
    if (can_throw(c, d, b) && (throw_a_brick(c, d, b) - eps <= a)) {
        printf("YES\n");
        return 0;
    } 
    if (can_throw(d, c, b) && (throw_a_brick(d, c, b) - eps <= a)) {
        printf("YES\n");
        return 0;
    } 
    printf("NO\n");
    return 0;
}
