#include<stdio.h>

unsigned f(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++) {
        s += 2 * i + 1;
    }
//    printf("!! %u\n", i-1);
    return x * (i - 1);
}

int main(void) {
    unsigned n;
    scanf("%u", &n);
    printf("%u\n", f(n));
    return 0;
}
