#include<stdio.h>
#include<string.h>

char s[1000001];

int main(void) {
    int k;
    scanf("%d\n", &k);
    fgets(s, 1000001, stdin);
    int n = strlen(s);
    s[--n] = 0;
    int wc = 1;
    for (int i = 0; i < n; ++i)
        if (s[i] == ' ') ++wc;
    int nsplen = n - wc + 1;
    int spw = (k - nsplen) / (wc - 1);
    int fbig = (k - nsplen) % (wc - 1);
    int cwc = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            printf("%c", s[i]);
        } else {
            int csps = spw;
            if (++cwc <= fbig) ++csps;
            for (int j = 0; j < csps; ++j) printf(" ");
        }
    }
    printf("\n");
    return 0;
}
