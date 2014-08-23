#include<stdio.h>

#define MOD (1<<22)

int map[MOD];

void proceed(long int k) {
    int kk;
    for (kk = k % MOD; (map[kk] != -1) && (map[kk] != k); kk = (kk + 1) % MOD);
    if (map[kk] == -1) {
        map[kk] = k;
    } else {
        map[kk] = -2;
    }
}

int main(void) {
    for (int i = 0; i < MOD; ++i) map[i] = -1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        proceed(t);
    }
    int ans1 = -1;
    int ans2 = -1;
    for (int i = 0; i < MOD; ++i) {
        if ((map[i] != -1) && (map[i] != -2)) {
            if (ans1 == -1) {
                ans1 = map[i];
            } else {
                ans2 = map[i];
            }
        }
    }
    if (ans1 > ans2) {
        int t = ans1; ans1 = ans2; ans2 = t;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
