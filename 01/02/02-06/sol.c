#include<stdio.h>

#define MAXN 10001

int v[MAXN], c[MAXN], t[MAXN];
int n;

void permutation(void) {
    for (int i = 0; i < n; ++i) t[i] = v[c[i]];
    for (int i = 0; i < n; ++i) c[i] = t[i];
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    for (int i = 0; i < n; ++i) --v[i];
    for (int i = 0; i < n; ++i) c[i] = i;
    for (int i = 0; i < 3; ++i) permutation();
    for (int i = 0; i < n; ++i) printf("%d ", c[i]+1);
    printf("\n");
    return 0;
}
