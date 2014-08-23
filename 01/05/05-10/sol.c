#include<stdio.h>

#define BASE 10

struct bignum {
    long long src[30001];
    int len;
    int sign;
};

struct bignum A;
struct bignum B;
struct bignum C;

struct bignum sum(struct bignum a, struct bignum b) {
    struct bignum res;
    for (int i = 0; i < 30001; ++i) res.src[i] = 0;
    int push = 0;
    int maxlen = a.len < b.len ? b.len : a.len;
    for (int i = 0; i < maxlen; ++i) {
        res.src[i] = (a.src[i] + b.src[i] + push) % BASE;
        push = (a.src[i] + b.src[i] + push) / BASE;
    }
    res.len = maxlen; res.sign = 1;
    if (push) {
        res.src[res.len++] = push;
    }
    return res;
}

int absless(struct bignum a, struct bignum b) {
    if (a.len != b.len) return a.len < b.len;
    for (int i = a.len-1; i >= 0; --i)
        if (a.src[i] != b.src[i]) return a.src[i] < b.src[i];
    return 0;
}

struct bignum _diff(struct bignum a, struct bignum b) {
    struct bignum res;
    for (int i = 0; i < 30001; ++i) res.src[i] = 0;
    int maxlen = a.len;
    for (int i = 0; i < maxlen; ++i) {
        if (a.src[i] < b.src[i]) {
            a.src[i] += BASE; --a.src[i+1];
        }
        res.src[i] = (a.src[i] - b.src[i]);
    }
    res.len = maxlen;
    res.sign = 1;
    while (res.len && !res.src[res.len-1]) --res.len;
    return res;
}

struct bignum diff(struct bignum a, struct bignum b) {
    int sign = 1;
    if (absless(a, b)) {
        struct bignum tmp = a;
        a = b;
        b = tmp;
        sign = -1;
    }
    struct bignum res = _diff(a, b);
    res.sign *= sign;
    return res;
}

struct bignum readbigint(void) {
    struct bignum res;
    res.len = 0;
    for (int i = 0; i < 10001; ++i) res.src[i] = 0;
    res.sign = 1;
    char tc;
    while (scanf("%c", &tc) == 1) {
        if ('0' > tc || tc > '9') {
            ungetc(tc, stdin);
            break;
        }
        tc -= '0';
        res.src[res.len++] = tc;
    }
    for (int i = 0; i < res.len / 2; ++i) {
        int tmp = res.src[i];
        res.src[i] = res.src[res.len - i - 1];
        res.src[res.len - i - 1] = tmp;
    }
    return res;
}

struct bignum multiply(struct bignum a, struct bignum b) {
    struct bignum res;
    res.sign = 1;
    for (int i = 0; i < 30001; ++i) res.src[i] = 0;
    for (int i = 0; i < a.len; ++i) {
        for (int j = 0; j < b.len; ++j) {
            res.src[i+j] += a.src[i] * b.src[j];
        }
    }
    for (int i = 0; i < a.len + b.len; ++i) {
        res.src[i+1] += res.src[i] / BASE;
        res.src[i] %= BASE;
    }
    res.len = a.len + b.len;
    while (res.len && !res.src[res.len-1]) --res.len;
    return res;
}

void printbigint(struct bignum a) {
    if (a.len == 0) {
        printf("0\n");
        return;
    }
    if (a.sign == -1) printf("-");
    for (int i = a.len-1; i >= 0; --i) {
        printf("%lld", a.src[i]);
    }
    printf("\n");
}

int main(void) {
    A = readbigint();
    char tc; scanf("%c", &tc);
    B = readbigint();
    if (tc == '+') C = sum(A, B);
    if (tc == '-') C = diff(A, B);
    if (tc == '*') C = multiply(A, B);
    printbigint(C);
    return 0;
}
