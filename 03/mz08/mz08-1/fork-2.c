#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

time_t
read_time_t(int fd)
{
    time_t result;
    read(fd, &result, sizeof(result));
    return result;
}

void
write_time_t(int fd, time_t val)
{
    write(fd, &val, sizeof(val));
}

void
pork_fork(void (*func)(int), int fd)
{
    pid_t pid = fork();
    if (pid == 0) {
        func(fd);
        exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return;
    }
}

void
seconds(int fd)
{
    time_t now = read_time_t(fd);
    struct tm *tm = localtime(&now);
    printf("S: %02d\n", tm->tm_sec);
}

void
minutes(int fd)
{
    pork_fork(seconds, fd);
    time_t now = read_time_t(fd);
    struct tm *tm = localtime(&now);
    printf("M: %02d\n", tm->tm_min);
}

void
hours(int fd)
{
    pork_fork(minutes, fd);
    time_t now = read_time_t(fd);
    struct tm *tm = localtime(&now);
    printf("H: %02d\n", tm->tm_hour);
}

int
main(void)
{
    int timepipe[2];
    pipe(timepipe);
    time_t now = time(NULL);
    for (int i = 0; i < 3; ++i) {
        write_time_t(timepipe[1], now);
    }
    pork_fork(hours, timepipe[0]);
    return 0;
}
