#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static long long *global_sum;

pid_t
proceed_file(char *filename)
{
    pid_t pid = fork();
    if (pid == 0) {
        FILE *fh = fopen(filename, "r");
        long long sum = 0;
        long long cur;
        while (fscanf(fh, "%lld", &cur) == 1) {
            sum += cur;
        }
        *global_sum += sum;
        exit(0);
    } else {
     return pid;
    }
}

int
main(int argc, char **argv)
{
    global_sum = mmap(NULL, sizeof *global_sum, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int file_cnt = argc - 1;
    for (int i = 1; i <= file_cnt; ++i) {
        proceed_file(argv[i]);
    }
    while (file_cnt) {
        int status;
        wait(&status);
        --file_cnt;
    }
    printf("%lld", *global_sum);
    return 0;
}
