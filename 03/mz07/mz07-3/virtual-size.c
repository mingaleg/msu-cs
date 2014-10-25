#include <stdio.h>

int
main(void)
{
    long st, fn;
    long sum = 0;
    while (scanf("%lx-%lx %*[^\n]\n", &st, &fn) == 2) {
        sum += fn - st;
    }
    printf("%ld\n", sum);
}
