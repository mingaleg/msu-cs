#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct ceil {
    int num;
    char str[101];
    int type; // 1 - num; 2 - str; 0 -empty
};

int key;
struct ceil table[10001][21];

int read_ceil(int row, int col) {
    char tc;
    struct ceil *foo = &table[row][col];
    scanf("%*[ ]");
    scanf("%1s", &tc);
    fprintf(stderr, "%c", tc);
    if (tc == '"') {
        scanf("%[^\"]s", foo->str);
        scanf("%c", &tc);
        scanf("%*[ ]");
        fprintf(stderr, "@%c@\n", tc);
        foo->type = 2;
    } else {
        ungetc(tc, stdin);
        scanf("%d", &foo->num);
        scanf("%*[ ]");
        foo->type = 1;
    }
    tc = '^';
    scanf("%*[ ]");
    int eoln = scanf("%1[;\n]s", &tc) != 1;
    scanf("%*[ ]");
    eoln |= (!tc || tc == '\n');
    fprintf(stderr, "?%c?\n", tc);
    return !eoln;
}

int cmp_ceil(struct ceil *a, struct ceil *b) {
    if (a->type == 2) {
        return strcmp(a->str, b->str);
    } else {
        return a->num - b->num;
    }
}

int cmp(const void *a, const void *b) {
    struct ceil *aa = (struct ceil *) a;
    struct ceil *bb = (struct ceil *) b;
    return cmp_ceil(aa+key, bb+key);
}

int read_row(int row) {
    int cnt = 0;
    char tc;
    fprintf(stderr, "#");
    scanf("%*[ ]");
    if (scanf("%1s", &tc) == EOF) {
        return 0;
    }
    if (!tc) return 0;
    fprintf(stderr, "!%c!", tc);
    fprintf(stderr, "*");
    ungetc(tc, stdin);
    while (read_ceil(row, cnt)) ++cnt; ++cnt;
    return 1;
}

void print_ceil(struct ceil *foo) {
    if (foo->type==2) printf("\"%s\"", foo->str); else printf("%d", foo->num);
}

void print_row(struct ceil *foo) {
    print_ceil(foo++);
    while (foo->type) {
        printf(";");
        print_ceil(foo++);
    }
    printf("\n");
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &key);
    int N = 0;
    while (read_row(N)) {
        ++N;
    }
    fprintf(stderr, "%d\n", N);
    qsort(table, N, sizeof(table[0]), cmp);
    for (int i = 0; i < N; ++i) {
        print_row(table[i]);
    }
    return 0;
}
