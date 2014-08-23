#include<stdio.h>
#include<stdlib.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char tc;
    long long ans;
    scanf("%lld", &ans);
    while (scanf("%c", &tc) == 1) {
        if (tc != '+' && tc != '-') continue;
        long long tn;
        scanf("%lld", &tn);
        fprintf(stderr, "%c %lld\n", tc, tn);
        if (tc == '+') ans += tn; else ans -= tn;
    }
    printf("%lld\n", ans);
    return 0;
}
