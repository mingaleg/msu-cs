#include<stdio.h>
#include<stdlib.h>

struct optimes {
    long r_time;
    long w_time;
    long wr_time;
};

struct op {
    long read;
    long data;
    unsigned long addr;
    long size;
    long value;
};

int
main(int argc, char **argv)
{
    struct optimes optimes;
    optimes.r_time = atoi(argv[1]);
    optimes.w_time = atoi(argv[2]);
    optimes.wr_time = atoi(argv[3]);

    struct op prev_op;
    struct op cur_op;
    cur_op.read = 0;
    cur_op.data = 0;
    cur_op.addr = 0;
    cur_op.size = 0;
    cur_op.value = 0;
    long sum_time = 0;

    char rw;
    char di;
    unsigned long addr;
    long size;
    long value;
    int first = 1;
    while(scanf("%c%c %lx %ld %ld\n",
                &rw, &di, &addr, &size, &value) == 5) {
        prev_op = cur_op;
        cur_op.read = rw == 'R';
        cur_op.data = di == 'D';
        cur_op.addr = addr;
        cur_op.size = size;
        cur_op.value = value;
        if (cur_op.read) {
            sum_time += optimes.r_time;
        } else {
            sum_time += optimes.w_time;
        }
        if (first) {
            first = 0;
            continue;
        }
        if (prev_op.addr == cur_op.addr &&
            prev_op.size == cur_op.size &&
            !prev_op.read && cur_op.read) {
            sum_time += optimes.wr_time - optimes.r_time - optimes.w_time;
        }
    }
    printf("%ld\n", sum_time);
}
