#include <stdio.h>
#include <stdlib.h>

#define MAXN 1024

static int
comp (const void * elem1, const void * elem2)
{
    double f = *((double*)elem1);
    double s = *((double*)elem2);
    if (f > s) return -1;
    if (f < s) return  1;
    return 0;
}

int
main(void)
{
    int n;
    double arr[1024];
    double newarr[1024];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", arr + i);
        newarr[i] = arr[i];
    }

    qsort(newarr, n, sizeof(double), comp);

    for (int i = 0; i < n; ++i) {
        printf("%d %.10g %.10g\n", i + 1, arr[i], newarr[i]);
    }
}
