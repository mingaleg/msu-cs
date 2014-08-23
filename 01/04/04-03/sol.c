#include<stdio.h>
#include<string.h>

int main(void) {
    char s[10001];
    scanf("%10000s", s);
    int n = strlen(s);
    for (int p = 1; p <= n; ++p) {
        int ok = 1;
        for (int i = 0; p+i < n; ++i) {
            if (s[i] != s[p+i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            printf("%d ", p);
        }
    }
    printf("\n");
}
