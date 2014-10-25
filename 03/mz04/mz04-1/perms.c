#include <stdio.h>
#include <stdlib.h>

char *
permstr(int perm)
{
    char *cur = calloc(sizeof(*cur), 10);
    char *on   = "rwxrwxrwx";
    char *off  = "---------";
    int di = 1;
    for (int i = 8; i >= 0; --i) {
        if (perm & di) {
            cur[i] = on[i];
        } else {
            cur[i] = off[i];
        }
        di <<= 1;
    }
    return cur;
}

int
main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i) {
        int perm;
        sscanf(argv[i], "%o", &perm);
        printf("%s\n", permstr(perm));
    }
}
