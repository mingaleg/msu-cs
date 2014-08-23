#include<stdio.h>
#include<string.h>

int main(void) {
    char s[256];
    scanf("%255s", s);
    int n = strlen(s);
    int bo = 0, be = 0, ao = 0, ae = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == 'A') {
            if (i % 2) ++ae; else ++ao;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            if (i % 2) --ae; else --ao;
        }
        if (bo + ae == be + ao) printf("%d ", i+1);
        if (s[i] == 'A') {
            if (i % 2) ++be; else ++bo;
        }
    }
    printf("\n");
    return 0;
}

