#include <unistd.h>
#include <stdlib.h>


char*
getlinell(int fd)
{
    char *str = calloc(2, sizeof(*str));
    int strsize = 2;
    int strlen = 0;
    char buff[2];
    while (1) {
        int foo = read(fd, buff, 1);
        if (!foo) {
            break;
        }
        ++strlen;
        if (strlen == strsize) {
            str = realloc(str, strsize * 2);
            strsize *= 2;
        }
        str[strlen - 1] = buff[0];
        if (buff[0] == '\n') {
            break;
        }
    }
    if (!strlen) {
        free(str);
        return 0;
    }
    str = realloc(str, strlen + 1);
    str[strlen] = 0;
    return str;
}
