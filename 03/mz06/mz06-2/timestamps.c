#include <stdio.h>
#include <time.h>

int main(int argc, char **argv) {
    FILE *inp = fopen(argv[1], "r");
    int ny, nm, nd, nhh, nmm, nss;
    time_t prev, now;
    int first = 1;
    while (fscanf(inp, "%d/%d/%d %d:%d:%d",
                 &ny, &nm, &nd, &nhh, &nmm, &nss) == 6) {
        struct tm ctm;
        ctm.tm_sec  = nss;
        ctm.tm_min  = nmm;
        ctm.tm_hour = nhh;
        ctm.tm_mday = nd;
        ctm.tm_mon  = nm - 1;
        ctm.tm_year = ny - 1900;
        ctm.tm_isdst = -1;

        now = mktime(&ctm);
        if (!first) {
            printf("%ld\n", now - prev);
        }
        first = 0;
        prev = now;
    }
    fclose(inp);
}
