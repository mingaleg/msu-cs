#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define FINGERS_ON_TWO_HANDS 10

int
count(FILE *fh, int *counts)
{
    int ch;
    int proc = 0;
    while ((ch = getc(fh)) != EOF) {
        if (('0' <= ch) && (ch <= '9')) {
            ++counts[ch - '0'];
        }
        proc++;
    }
    return proc;
}

int
main(void)
{
    char filename[PATH_MAX + 1];
    fgets(filename, PATH_MAX, stdin);
    filename[strlen(filename) - 1] = 0;
    FILE *fh = fopen(filename, "r");

    int cnt[FINGERS_ON_TWO_HANDS];
    for (int i = 0; i < FINGERS_ON_TWO_HANDS; ++i) {
        cnt[i] = 0;
    }
    count(fh, cnt);
    fclose(fh);

    for(int i = 0; i < FINGERS_ON_TWO_HANDS; ++i) {
        printf("%d %d\n", i, cnt[i]);
    }
}
