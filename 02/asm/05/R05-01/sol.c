#include<stdio.h>

unsigned long f(unsigned long p) {
    if (!p) return 1;
    return 3*f(p-1);
}

int main(void) {
    unsigned long p;
    scanf("%lu", &p);
    printf("%lu\n", f(p));
}
