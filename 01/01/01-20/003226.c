#include<stdio.h>
#include<math.h>

#define eps 1e-6

double throw_a_brick(double a, double b, double w) {
    if (a - eps <= w) return b;
    double alpha = asin(w / sqrt(a*a + b*b)) - asin(a / sqrt(a*a + b*b));
    double h = sqrt(a*a + b*b - w*w + 2*a*b*sin(2*alpha));
    return h;
}

int main(void) {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    if (throw_a_brick(a, b, c) - eps <= d) {
        printf("YES\n");
        return 0;
    }
    if (throw_a_brick(b, a, c) - eps <= d) {
        printf("YES\n");
        return 0;
    }
    if (throw_a_brick(a, b, d) - eps <= c) {
        printf("YES\n");
        return 0;
    }
    if (throw_a_brick(b, a, d) - eps <= c) {
        printf("YES\n");
        return 0;
    }

    printf("NO\n");
    return 0;
}
