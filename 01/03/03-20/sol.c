#include<stdio.h>

#define MOD (1ll << 32)
#define QMAX (1ll << 16)

long long gcd(long long a, long long b, long long* x, long long* y) {
    if (!a) {
        *x = 0; *y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b%a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return d;
}

unsigned f(unsigned x)
{
    long long s = 0;
    unsigned i;
    for (i = 0; s <= x; i++) {
        s += 2 * i + 1;
    }
    return x * (i - 1);
}


unsigned reverse(unsigned a, long long mod) {
    long long x, y;
    long long g = gcd(a, mod, &x, &y);
    if (g != 1) return 0;
    x = (x % mod + mod) % mod;
    return (unsigned)x;
}

unsigned magic(unsigned n, unsigned ans, unsigned mod) {
    unsigned oldn = n;
    do {
        if (f(n) == ans) return n;
        n += mod;
    } while (n != oldn);
    return 0;
}

int check_q(unsigned q, unsigned a, unsigned* ans) {
    long long t1, t2;
    long long g1 = gcd(q, MOD, &t1, &t2);
    long long oldq = q;
    unsigned olda = a;
    long long mod = MOD;
    q /= g1; a /= g1; mod /= g1;
    unsigned r = reverse(q, mod);
    if (!r) return 0;
    if (mod != MOD) {
        r = (r*a) % mod;
    } else {
        r = r*a;
    }
    unsigned oldr = r;
    do {
        if ((oldq*oldq <= r) && (r <= (oldq+1)*(oldq+1)-1) && f(r) == olda) {
            *ans = r;
            return 1;
        }
        r += mod;
    } while (r != oldr);
    return 0;
}

int main(void) {
    unsigned n;
    scanf("%u", &n);
    if (!n) {
        printf("0\n");
        return 0;
    }
    for (unsigned q = 0; q < QMAX; ++q) {
        unsigned ans;
        if (check_q(q, n, &ans)) {
            printf("%u\n", ans);
            return 0;
        }
    }
    printf("AZAZA\n");
}
