#include<stdio.h>

int main(void){
    int n;
    int m1, m2, m3;
    scanf("%d", &n);
    scanf("%d%d%d", &m1, &m2, &m3);

    if (m1 < m2) {
        int t = m1; m1 = m2; m2 = t;
    }
    if (m1 < m3) {
        int t = m1; m1 = m3; m3 = t;
    }
    if (m2 < m3) {
        int t = m2; m2 = m3; m3 = t;
    }

    for (int i = 3; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t > m3) m3 = t;
        if (m3 > m2) {
            int t = m2; m2 = m3; m3 = t;
        }
        if (m2 > m1) {
            int t = m1; m1 = m2; m2 = t;
        }
    }
    printf("%d %d %d\n", m1, m2, m3);
    return 0;
}
