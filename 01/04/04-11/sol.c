#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[2001];
int n;

int around(int pos, int *l, int *r) {
    *l = *r = pos;
    while ((*l) > 0 && ('0' <= s[(*l)-1]) && (s[(*l)-1] <= '9')) --(*l);
    while ((*r) < n && ('0' <= s[(*r)+1]) && (s[(*r)+1] <= '9')) ++(*r);
    return (pos != (*l)) && (pos != (*r));
}

int main(void) {
    scanf("%2000s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int tl, tr;
        if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') continue;
        if (!around(i, &tl, &tr)) continue;
        char sl[2001], sr[2001];
        strncpy(sl, s+tl, i - tl); sl[i-tl] = 0;
        strncpy(sr, s+i+1, tr - i); sr[tr-i] = 0;
        long vl = atol(sl), vr = atol(sr);
        long res = 0;
        if (s[i] == '+') res = vl + vr;
        if (s[i] == '-') res = vl - vr;
        if (s[i] == '*') res = vl * vr;
        if (s[i] == '/') {
            if (vr == 0) continue;
            res = vl / vr;
        }
        if (res > 120000) continue;
        printf("%s %c %s = %ld", sl, s[i], sr, res);

        printf("\n");
    }
}