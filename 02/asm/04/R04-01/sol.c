#include<stdio.h>

int main(void) {
    long ecx, ebx, eax;
    scanf("%ld", &ecx);

    ebx = 1;
    eax = 0;

    while (ecx) {
        eax ^= ebx;
        ebx ^= eax;
        eax ^= ebx;

        ebx += eax;

        --ecx;
    }

    printf("%ld\n", eax);
    return 0;
}
