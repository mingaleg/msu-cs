#include<stdio.h>

#define MAXN 4000

long a[MAXN];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+2; j < n; j += 2) {
            if ((a[i] + a[j]) == 2*a[(i+j)/2]) ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
