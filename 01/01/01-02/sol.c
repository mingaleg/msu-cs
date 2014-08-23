#include<stdio.h>

int main(void){
    int max, maxcnt;
    int n;

    scanf("%d", &n);
    scanf("%d", &max);
    maxcnt = 1;

    for (int i = 1; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == max) {
            maxcnt += 1;
        } else if (tmp > max) {
            max = tmp;
            maxcnt = 1;
        }
    }
    printf("%d\n", maxcnt);
}
