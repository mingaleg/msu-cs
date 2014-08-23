#include<stdio.h>
#include<stdlib.h>

int16_t read16(void) {
    const int size = 2;
    unsigned char bytes[8];
    fread(bytes, size, 1, stdin);
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        ans |= (int) bytes[i] << (8*(size-i-1));
    }
    return ans;
}
int32_t read32(void) {
    const int size = 4;
    unsigned char bytes[8];
    fread(bytes, size, 1, stdin);
    int32_t ans = 0;
    for (int i = 0; i < size; ++i) {
        ans |= (long) bytes[i] << (8*(size-i-1));
    }
    return ans;
}

void write64(long long n) {
    int size = 8;
    static union {
        long long n;
        char c[8];
    } foo;
    foo.n = n;
    for (int i = 0; i < size; ++i) fwrite(&foo.c[size-i-1], sizeof(char), 1, stdout);
}

int main(void) {
    freopen("matrix.in", "r", stdin);
    freopen("trace.out", "w", stdout);
    int n = read16();
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long tmp = read32();
            if (i == j) {
                ans += tmp;
            }
        }
    }
    write64(ans);
    return 0;
}
