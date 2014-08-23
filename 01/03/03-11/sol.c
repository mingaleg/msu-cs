#include<stdio.h>

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void simplify(int* a, int* b) {
    int g = gcd(*a, *b);
    *a /= g;
    *b /= g;
}

void sum(int a1, int b1, int a2, int b2, int* c1, int* c2) {
    *c1 = a1*b2 + a2*b1;
    *c2 = b1*b2;
    simplify(c1, c2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int ansa = 0, ansb = 1;
    for (int i = 0; i < n; ++i) {
        int ta, tb;
        scanf("%d%d", &ta, &tb);
        sum(ta, tb, ansa, ansb, &ansa, &ansb);
    }
    printf("%d %d %d\n", ansa / ansb, ansa % ansb, ansb);
    return 0;
}
