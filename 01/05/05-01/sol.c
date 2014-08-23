#include<stdio.h>
#include<stdlib.h>

struct complex {
    long long re, im;
};

int main(void) {
    int n;
    scanf("%d", &n);

    struct complex **matrix = (struct complex **) malloc(n*sizeof(struct complex *));
    for (int i = 0; i < n; ++i) {
        matrix[i] = (struct complex *) malloc(n*sizeof(struct complex));
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            scanf("%lld%lld", &matrix[i][j].re, &matrix[i][j].im);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%lld %lld ", matrix[j][i].re, -matrix[j][i].im);
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i)
        free(matrix[i]);
    free(matrix);
    return 0;
}
