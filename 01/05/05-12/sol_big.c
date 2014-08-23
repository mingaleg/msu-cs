#include<stdio.h>

long long gcd(long long x, long long y) {
    if (!x) return y;
    return gcd(y % x, x);
}

void _simplify(long long *x, long long *y) {
    long long g = gcd(*x, *y);
    *x /= g;
    *y /= g;
    if (*y < 0) {
        *x *= -1; *y *= -1;
    }
}

struct frac {
    long long p;
    long long q;
};

struct frac sum(struct frac a, struct frac b) {
    struct frac res;
    res.p = a.p*b.q + b.p*a.q;
    res.q = a.q * b.q;
    _simplify(&res.p, &res.q);
    return res;
}

struct frac neg(struct frac a) {
    a.p *= -1;
    return a;
}

struct frac mul(struct frac a, struct frac b) {
    struct frac res;
    res.p = a.p * b.p;
    res.q = a.q * b.q;
    _simplify(&res.p, &res.q);
    return res;
}

struct frac div(struct frac a, struct frac b) {
    struct frac res;
    res.p = a.p * b.q;
    res.q = a.q * b.p;
    _simplify(&res.p, &res.q);
    return res;
}

struct frac readfrac(void) {
    struct frac res;
    scanf("%lld", &res.p);
    res.q = 1;
    return res;
}

struct frac a[500][501];
struct frac x[500];

int read(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            a[i][j] = readfrac();
        }
    }
    return n;
}

int straight_step(int n) {
    for (int k = 1; k < n; ++k) {
        for (int j = k; j < n; ++j) {
            struct frac m = div(a[j][k-1], a[k-1][k-1]);
            for (int i = 0; i <= n; ++i) {
                a[j][i] = sum(a[j][i], neg(mul(m, a[k-1][i])));
            }
        }
    }
    return n;
}

int reverse_step(int n) {
    for (int i = n-1; i >= 0; --i) {
        for (int k = 0; k < i; ++k) {
            struct frac foo = div(a[k][i], a[i][i]);
            a[k][n] = sum(a[k][n], neg(mul(foo, a[i][n])));
            a[k][i].p = 0; a[k][i].q = 1;
        }
        x[i] = div(a[i][n], a[i][i]);
    }
    return n;
}

int write(int n) {
    for (int i = 0; i < n; ++i) {
        _simplify(&x[i].p, &x[i].q);
        printf("%lld\n", x[i].p);
    }
    return n;
}

int main(void) {
    write(reverse_step(straight_step(read())));
    return 0;
}
