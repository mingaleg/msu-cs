#include<stdio.h>

int main(void) {
    long int n;
    long long max_mul, min_mul;
    long int max1, max2;
    long int min1, min2;

    scanf("%ld", &n);

    scanf("%ld %ld", &max1, &max2);
    if (max1 < max2) {
        int t = max1; max1 = max2; max2 = t;
    }
    min1 = max2; min2 = max1;

    for (int i = 2; i < n; ++i) {
        long int t;
        scanf("%ld", &t);
        if (max2 < t) max2 = t;
        if (max1 < max2) {
            int t = max1; max1 = max2; max2 = t;
        }
        if (min2 > t) min2 = t;
        if (min1 > min2) {
            int t = min1; min1 = min2; min2 = t;
        }
    }

    max_mul = (long long) max1 * max2;
    min_mul = (long long) min1 * min2;

    if (max_mul > min_mul) {
        printf("%ld %ld\n", max2, max1);
    } else {
        printf("%ld %ld\n", min1, min2);
    }
    return 0;
}
