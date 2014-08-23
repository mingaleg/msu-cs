#include<stdio.h>

unsigned f(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++) {
        s += 2 * i + 1;
    }
    return x * (i - 1);
}

int main(void) {
    unsigned prev = 0;
    int tmp = 0;
    for (unsigned x = 0; !tmp || x; ++x) {
        tmp = 1;
        unsigned cur = f(x);
        if (cur < prev) printf("%u\n", x);
        if (x % 10000000 == 0) printf("!!!! %u\n", x);
        prev = cur;
    }
    return 0;
}
