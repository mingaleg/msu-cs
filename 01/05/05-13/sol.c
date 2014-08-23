#include<stdio.h>
#include<stdlib.h>

struct deque_node {
    int x, y;
    struct deque_node *next, *prev;
};

struct deque {
    struct deque_node *head, *tail;
};

struct deque_node * mknode(int x, int y) {
    struct deque_node *foo = (struct deque_node *) malloc(sizeof(struct deque_node));
    foo->x = x; foo->y = y;
    foo->next = 0; foo->prev = 0;
    return foo;
}

void push_front(struct deque *d, int x, int y) {
    struct deque_node *foo = mknode(x, y);
    foo->next = d->head;
    if (d->head) {
        d->head->prev = foo;
        d->head = foo;
    } else {
        d->head = foo; d->tail = foo;
    }
}

void push_back(struct deque *d, int x, int y) {
    struct deque_node *foo = mknode(x, y);
    foo->prev = d->tail;
    if (d->tail) {
        d->tail->next = foo;
        d->tail = foo;
    } else {
        d->head = foo; d->tail = foo;
    }
}

void pop_front(struct deque *d, int *x, int *y) {
    *x = d->head->x; *y = d->head->y;
    struct deque_node *foo = d->head;
    if (d->head->next) d->head->next->prev = 0;
    d->head = d->head->next;
    if (!d->head) d->tail = 0;
    free(foo);
}

void pop_back(struct deque *d, int *x, int *y) {
    *x = d->tail->x; *y = d->tail->y;
    struct deque_node *foo = d->tail;
    if (d->tail->prev) d->tail->prev->next = 0;
    d->tail = d->tail->prev;
    if (!d->tail) d->head = 0;
    free(foo);
}

long long llabs(long long a) {
    return (a > 0) ? a : -a;
}

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

int main(void) {
    int n, m, sx, sy, ex, ey;
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey);
    long long **a = (long long **) malloc(sizeof(long long *) * n);
    int **id = (int **) malloc(sizeof(int *) * n);
    long long **D = (long long **) malloc(sizeof(long long *) * n);
    for (int i = 0; i < n; ++i) {
        a[i] = (long long *) malloc(sizeof(long long) * m);
        id[i] = (int *) malloc(sizeof(int) * m);
        D[i] = (long long *) malloc(sizeof(long long) * m);
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
            id[i][j] = 2;
            D[i][j] = 10000ll * 1100000ll * 2ll;
        }
    }
    struct deque *q = (struct deque *) malloc(sizeof(struct deque));
    q->head = q->tail = 0;
    push_back(q, sx, sy);
    D[sx][sy] = 0;
    id[sx][sy] = 1;
    while (q->head) {
        int cx, cy;
        pop_front(q, &cx, &cy);
        id[cx][cy] = 0;
        const int dist[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int dir = 0; dir < 4; ++dir) {
            int tx = cx + dist[dir][0], ty = cy + dist[dir][1];
            if (tx < 0 || tx >= n) continue;
            if (ty < 0 || ty >= m) continue;

            if (id[tx][ty] == 2) {
                D[tx][ty] = D[cx][cy] + llabs(a[cx][cy] - a[tx][ty]);
                push_back(q, tx, ty);
                id[tx][ty] = 1;
            } else if (id[tx][ty] == 1) {
                D[tx][ty] = min(D[tx][ty], D[cx][cy] + llabs(a[cx][cy] - a[tx][ty]));
            } else {
                if (D[tx][ty] > D[cx][cy] + llabs(a[cx][cy] - a[tx][ty])) {
                    D[tx][ty] = D[cx][cy] + llabs(a[cx][cy] - a[tx][ty]);
                    id[tx][ty] = 1;
                    push_front(q, tx, ty);
                }
            }
        }
    }
    printf("%lld\n", D[ex][ey]);
    return 0;
}
