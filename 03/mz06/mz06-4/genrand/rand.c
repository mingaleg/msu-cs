#include <stdlib.h>

int rand_range(int low, int high) {
    double rval = (float)rand() / RAND_MAX;
    return (int)(rval * (high - low) + low);
}
