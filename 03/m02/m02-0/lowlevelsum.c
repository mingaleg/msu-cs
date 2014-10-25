#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void
proceed(char chr, int *res, int *sgn, int *st, int *err)
{
    switch (*st) {
        case 0:
            if (chr == '-') {
                *sgn = -1;
                *st = 1;
            } else if ('0' <= chr && chr <= '9') {
                *res = chr - '0';
                *st = 1;
            } else if (!(chr == '\t' || chr == '\n' ||
                        chr == '\r' || chr == ' ' || chr == '+')) {
                *err = 1;
            }
            break;
        case 1:
            if ('0' <= chr && chr <= '9') {
                *res = *res * 10 + chr - '0';
            } else if (chr == '\t' || chr == '\n' ||
                    chr == '\r' || chr == ' ') {
                *st = 2;
            } else {
                *err = 1;
            }
            break;
        default:
            *err = 1;
    }
}


int new_char(char *buff, int *curbuff, int *buffpos, int buffsize) {
    if (*buffpos == *curbuff) {
        *curbuff = read(STDIN_FILENO, buff, buffsize);
        *buffpos = 0;
        if (*curbuff <= 0) {
            return -1;
        }
    }
    int ret = buff[*buffpos];
    ++(*buffpos);
    return ret;
}

int
read_int(int *err, char *buff, int *curbuff, int *buffpos, int buffsize)
{
    int res = 0;
    int st = 0;
    int sgn = 1;
    *err = 0;
    while (1) {
        int ch = new_char(buff, curbuff, buffpos, buffsize);
        if (ch < 0) {
            break;
        }
        proceed(ch, &res, &sgn, &st, err);
        if (st == 2) {
            break;
        }
    }
    if (st != 2) {
        *err = 1;
        return 0;
    }
    return sgn * res;
}

int
main(void)
{
    const int buffsize = 4 * 1024;
    char *buff = (char *) calloc(buffsize, sizeof(*buff));
    int curbuff = 0;
    int buffpos = 0;
    long long ans = 0;
    while (1) {
        int err;
        int foo = read_int(&err, buff, &curbuff, &buffpos, buffsize);
        if (err) {
            break;
        }
        ans += foo;
    }
    free(buff);
    printf("%lld\n", ans);
}
