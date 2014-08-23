#include<stdio.h>

int main(void) {
    long ecx, ebx, eax, edx;
    scanf("%ld", &ecx);
    edx = 0;
    if (ecx & 1) {
        ecx >>= 1;
        goto end;
    }

    ecx >>= 1;
    do {
        scanf("%ld", &eax);
        scanf("%ld", &ebx);
        eax *= ebx;
        edx += eax;
        --ecx;
    } while (ecx);
    
    end:
    printf("%ld\n", edx);

    return 0;
}
