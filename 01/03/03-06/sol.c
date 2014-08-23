#include<stdio.h>

long K(long i) {
    if (i <= 3) return i;
    if (i % 2) return 2*K(i+3);
    return 3 + K(i / 2);
}

int main(void) {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", K(n));
    return 0;
}
