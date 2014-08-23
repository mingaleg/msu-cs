#include<stdio.h>

#define MAXN 10000

long a[MAXN], b[MAXN];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%ld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%ld", &b[i]);
    long ans = 0;
    for (int i = 0; i < n; ++i) ans += (a[i] > b[i] ? a[i] : b[i]);
    printf("%ld\n", ans);
    return 0;
}
