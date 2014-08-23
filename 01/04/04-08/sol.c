#include<stdio.h>
#include<string.h>

int compile(char a, char b, char c) {
    return (a - '0') * 100 + (b - '0') * 10 + (c - '0');
}

int main(void) {
    char s[101];
    scanf("%100s", s);
    int n = strlen(s);
    int used[1000];
    for (int i = 0; i < 1000; ++i) used[i] = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = a+1; b < n; ++b) {
            for (int c = b+1; c < n; ++c) {
                used[compile(s[a], s[b], s[c])] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 100; i < 1000; ++i) ans += used[i];
    printf("%d\n", ans);
    return 0;
}
