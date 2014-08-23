#include<stdio.h>
#include<stdlib.h>

int matrix[500][500][2];
int step, n, m, cur;

int full(void) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!matrix[i][j][cur]) return 0;
    return 1;
}

int proceed(void) {
    int pre = cur;
    ++step; cur ^= 1;
    int full = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            matrix[i][j][cur] = matrix[i][j][pre];
            if (i > 0   && matrix[i-1][j][pre]) matrix[i][j][cur] = 1;
            if (i < n-1 && matrix[i+1][j][pre]) matrix[i][j][cur] = 1;
            if (j > 0   && matrix[i][j-1][pre]) matrix[i][j][cur] = 1;
            if (j < m-1 && matrix[i][j+1][pre]) matrix[i][j][cur] = 1;
            if (!matrix[i][j][cur]) full = 0;
        }
    return full;
}

int main(void) {
    int k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int tx, ty;
        scanf("%d%d", &ty, &tx);
        matrix[--tx][--ty][0] = 1;
    }
    step = 0; cur = 0;
    if (!full()) while(!proceed());
    printf("%d\n", step);
}
