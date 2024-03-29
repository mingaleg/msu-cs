#include<stdio.h>
#include<string.h>

char s[2000001];
int pos0[2000];
int cnt0;
int n;

int getint(int p1, int p2) {
    return (pos0[p2%cnt0] - pos0[p1%cnt0] + n) % n;
}

int less(int p1, int p2) {
    int ch = 0;
    while (getint(p1+ch, p1+ch+1) == getint(p2+ch, p2+ch+1) && ch < cnt0) ++ch;
    return getint(p1+ch, p1+ch+1) < getint(p2+ch, p2+ch+1);
}

int main(void) {
    scanf("%2000000s", s);
    n = strlen(s);
    cnt0 = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '0') pos0[cnt0++] = i;
    int ans = 0;
    for (int i = 1; i < cnt0; ++i) if (less(i, ans)) ans = i;
    for (int i = 0; i < n; ++i) printf("%c", s[(pos0[ans]+i)%n]);
    printf("\n");
    return 0;
}
