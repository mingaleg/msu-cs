#include <stdlib.h>
#include <stdio.h>
#include "rand.h"


int main(int argc, char **argv) {
    int count = atoi(argv[1]);
    int low = atoi(argv[2]);
    int high = atoi(argv[3]);
    int seed = atoi(argv[4]);
    srand(seed);
    for (int i = 0; i < count; ++i) {
        printf("%d\n", rand_range(low, high));
    }
    return 0;
}
