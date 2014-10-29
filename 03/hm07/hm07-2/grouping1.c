#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int
execute(char *cmd)
{
    pid_t pid = fork();
    if (pid == 0) {
        execlp(cmd, cmd, NULL);
        return -1;
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status) == 0 && WIFEXITED(status);
    }
}

int
main(int argc, char **argv)
{
    if ((execute(argv[1]) || execute(argv[2])) && execute(argv[3])) {
        return 0;
    } else {
        return 1;
    }
}
