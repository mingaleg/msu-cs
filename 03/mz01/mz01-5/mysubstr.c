#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prefix function
int
prefix(const char* s, int* pi)
{
    pi[0] = 0;
    if (!s[0]) return 0;
    int i;
    for (i = 1; s[i]; ++i) {
        int j = pi[i - 1];
        while ((j > 0) && (s[i] != s[j])) {
            j = pi[j - 1];
        }
        pi[i] = j;
        if (s[i] == s[j]) {
            ++pi[i];
        }
    }
    return i;
}

int
fireproof_substr(const char* sample, const char* pattern, int direction)
{
    int smp_len = strlen(sample);
    int ptr_len = strlen(pattern);
    if (ptr_len == 0) {
        return (direction > 0) ? 0 : smp_len;
    }
    char *foo = (char*) calloc(smp_len + ptr_len + 2, sizeof(char));
    strcpy(foo, pattern);
    foo[ptr_len] = '#';
    strcpy(foo + ptr_len + 1, sample);
    int *pi = (int*) calloc(smp_len + 1 + ptr_len, sizeof(int));
    prefix(foo, pi);
    int pos = -1;
    for (int i = 0; i < smp_len; ++i) {
        if (pi[ptr_len + 1 + i] == ptr_len) {
            pos = i - ptr_len + 1;
            if (direction > 0) {
                break;
            }
        }
    }
    free(foo);
    free(pi);
    return pos;
}

int
mysubstr(const char* pattern, const char* sample)
{
    int ptr_len = strlen(pattern);
    char *aster_addr = strchr(pattern, '*');
    if (!aster_addr) {
        return fireproof_substr(sample, pattern, 1);
    }
    int aster = aster_addr - pattern;
    char *pref = (char*) calloc(aster + 1, sizeof(char));
    strncpy(pref, pattern, aster);
    char *suff = (char*) calloc(ptr_len - aster, sizeof(char));
    strcpy(suff, pattern + aster + 1);
    int pref_match = fireproof_substr(sample, pref, 1);
    int suff_match = fireproof_substr(sample, suff, -1);
    free(pref);
    free(suff);
    if ((pref_match == -1) || (suff_match == -1)) {
        return -1;
    }
    if (pref_match + aster > suff_match) {
        return -1;
    }
    return pref_match;
}

#ifdef SHHDUPLOCAL
int
main(void)
{
    char s[200];
    char t[200];
    scanf("%s %s", s, t);
    printf("%d\n", mysubstr(s, t));
    return 0;
}
#endif
