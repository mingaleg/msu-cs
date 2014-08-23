#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int c_cmp1(const void * a, const void * b) {
    int aa = *(int*)a;
    int bb = *(int*)b;
    if (aa < bb) return -1;
    if (aa == bb) return 0;
    if (aa > bb) return 1;
}
int c_cmp2(const void * a, const void * b) {
    return c_cmp1(b, a);
}

extern int count_comp; int count_comp;
extern int count_swap; int count_swap;

void generator(int type, int n, int * a) {
    srand(type * time(NULL));
    for (int i = 0; i < n; ++i)
        a[i] = rand() * rand();
    if (type == 1) {
        //increasing
        qsort(a, n, sizeof(int), c_cmp1);
        return;
    }
    if (type == 2) {
        //decreasing
        qsort(a, n, sizeof(int), c_cmp2);
        return;
    }
    //random
    return;
}

extern int CMP(int a, int b);
extern int swap(int * a, int * b);

#include "shell_sort.c"
#include "heap_sort.c"

extern unsigned long long timestamp(void);

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 4; ++i) {
        count_comp = 0;
        count_swap = 0;
        int * a = (int *) malloc(sizeof(int) * n);
        
        generator(i, n, a);
        unsigned long long start = timestamp();
        shell_sort(n, a);
        unsigned long long finish = timestamp();
        printf("SHELL SORT: %d %d %llu\n", count_comp, count_swap, finish - start);

        generator(i, n, a);
        start = timestamp();
        heap_sort(n, a);
        finish = timestamp();
        printf("HEAP  SORT: %d %d %llu\n", count_comp, count_swap, finish - start);
        
        free(a);
    }
}
