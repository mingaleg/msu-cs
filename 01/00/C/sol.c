#include<stdio.h>

int main(void) {
    long sum = 0;
    int t;
    do {
        scanf("%d", &t);
        sum += t;
    } while (t);
    printf("%ld\n", sum);
    return 0;
}
