#include<stdio.h>

int solve(int n, int cn) {
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    if (!cn) return solve(n, cn+1);
    if (cn*2 == n) return 1;
    if (!solve(n, cn+1)) return 0;
    int x2, y2;
    scanf("%d%d", &x2, &y2);
    if (x1 != -x2) return 0;
    if (y1 != +y2) return 0;
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf(solve(n, 0) ? "Yes\n" : "No\n");
    return 0;
}
