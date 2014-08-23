#include<stdio.h>

int main(void) {
    int front[8], right[8];
    int f[8][8];
    for (int i = 0; i < 8; ++i) scanf("%d", &front[i]);
    for (int i = 0; i < 8; ++i) scanf("%d", &right[i]);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            f[i][j] = front[i];
        }
    }
    for (int j = 0; j < 8; ++j) {
        int max = -1;
        for (int i = 0; i < 8; ++i) {
            if (f[i][j] > max) max = f[i][j];
        }
        if (max < right[j]) {
            printf("-1\n");
            return 0;
        }
        for (int i = 0; i < 8; ++i) {
            f[i][j] = (f[i][j] < right[j]) ? f[i][j] : right[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        int max = -1;
        for (int j = 0; j < 8; ++j) {
            if (f[i][j] > max) max = f[i][j];
            ans += f[i][j];
        }
        if (front[i] != max) {
            printf("-1");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
