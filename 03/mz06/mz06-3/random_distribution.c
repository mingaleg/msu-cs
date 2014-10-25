#include <stdio.h>
#include <stdlib.h>

enum {
    MAXN= 100
};

int main(void) 
{
    int n;
    long vals[MAXN];
    int probs[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld %d", &vals[i], &probs[i]);
    }
    int m;
    long seed;
    scanf("%d %ld", &m, &seed);
    srand(seed);
    for (int i = 0; i < m; ++i) {
        double rval = 100 * (float)rand() / RAND_MAX;
        int cval = 0;
        int j;
        for (j = 0; cval + probs[j] < rval; ++j) {
            cval += probs[j];
        }
        printf("%ld\n", vals[j]);
    }
}
