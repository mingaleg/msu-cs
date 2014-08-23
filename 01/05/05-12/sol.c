#include<stdio.h>
#include<tgmath.h>

double a[500][501];
double x[500];

int read(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
    return n;
}

int straight_step(int n) {
    for (int k = 1; k < n; ++k) {
        int tk = -1;
        for (int j = k-1; j < n; ++j) {
            if ((fabs(a[j][k-1]) > 1e-6) && ((tk == -1) || (fabs(a[j][k-1]) < fabs(a[tk][k-1])))) tk = j;
        }
        for (int j = 0; j <= n; ++j) {
            double tmp = a[k-1][j];
            a[k-1][j] = a[tk][j];
            a[tk][j] = tmp;
        }

        for (int j = k; j < n; ++j) {
            long double m = a[j][k-1] / a[k-1][k-1];
            for (int i = 0; i <= n; ++i) {
                a[j][i] -= m*a[k-1][i];
            }
        }
    }
    return n;
}

int reverse_step(int n) {
    for (int i = n-1; i >= 0; --i) {
        for (int k = 0; k < i; ++k) {
            double foo = a[k][i] / a[i][i];
            a[k][n] -= foo * a[i][n];
            a[k][i] = 0;
        }
        x[i] = a[i][n]/a[i][i];
    }
    return n;
}

int write(int n) {
    for (int i = 0; i < n; ++i) printf("%d\n", (int) round(x[i]));
    return n;
}

int main(void) {
    write(reverse_step(straight_step(read())));
    return 0;
}
