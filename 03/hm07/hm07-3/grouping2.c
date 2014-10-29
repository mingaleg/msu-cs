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
execute_or(char *cmd1, char *cmd2)
{
    pid_t pid = fork();
    if (pid == 0) {
        int status = execute(cmd1) || execute(cmd2);
        exit(!status);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status) == 0 && WIFEXITED(status);
    }
}

int
main(int argc, char **argv)
{
    if (execute_or(argv[1], argv[2])  && execute(argv[3])) {
        return 0;
    } else {
        return 1;
    }
}
