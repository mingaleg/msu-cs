#include<stdio.h>

unsigned long get_consecutive_bits(unsigned long N, int K, int offset) {
    return (N & (((1 << K) - 1) << offset)) >> offset;
}

int main(void) {
    unsigned long N;
    int K;
    scanf("%lu %d", &N, &K);

    unsigned long max = 0;
    for(int i = 0; i + K <= sizeof(N)*8; ++i) {
        unsigned long tmp = get_consecutive_bits(N, K, i);
        if (tmp > max) max = tmp;
    }

    printf("%lu\n", max);
}
