#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(void)
{
    int done = 0;
    long n;
    while (!done) {
        if (scanf("%ld", &n) != 1) {
            exit(0);
        }
        pid_t pid = fork();
        done = pid != 0;
    }
    wait(NULL);
    printf("%ld\n", n);
    return 0;
}
