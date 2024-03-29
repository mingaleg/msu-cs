#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps (1e-6)

struct foo {
    int size;
    int cnt;
};

struct foo status[20];

int m;

void proceed(int level, int width) {
    if (!level) {
        printf("Yes\n");
        exit(0);
    }
    for (int i = 0; i < m; ++i) {
        if (status[i].cnt >= level && status[i].size*level < width) {
            status[i].cnt -= level;
            proceed(level-1, status[i].size*level);
            status[i].cnt += level;
        }
    }
}

int main(void) {
    scanf("%d", &m);
    int cnt = 0; int max_width = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &(status[i].size), &(status[i].cnt));
        cnt += status[i].cnt;
        if (max_width < status[i].size) max_width = status[i].size;
    }
    // n*(n+1) = 2*cnt
    // n**2 + n - 2*cnt = 0
    // D = 1 + 8*cnt
    double lev = (sqrt(1 + 8*cnt) - 1) / 2;
    if (fabs((int)(lev+eps) - lev) > eps) {
        printf("No\n");
        return 0;
    }
    int levels = (int)(lev+eps);
    proceed(levels, max_width*cnt+1);
    printf("No\n");
    return 0;
}
