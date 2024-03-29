#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *l, *r;
};

struct node* mk_node(int val) {
    struct node *foo = (struct node *) malloc(sizeof(struct node));
    foo->val = val;
    foo->l = foo->r = 0;
    return foo;
}

void insert(struct node *foo, struct node *bar) {
    bar->r = foo->r;
    foo->r->l = bar;
    bar->l = foo;
    foo->r = bar;
}

void move_seg_to(struct node *left, struct node *right, struct node *dest) {
    left->l->r = right->r;
    right->r->l = left->l;
    right->r = dest->r;
    dest->r->l = right;
    dest->r = left;
    left->l = dest;
}

void init_list(struct node **begin, struct node **end) {
    *begin = mk_node(-1);
    *end = mk_node(-1);
    (*begin)->r = *end;
    (*end)->l = *begin;
}

struct node *ref[100000];

void proceed(struct node *begin, struct node *end, int b, int c) {
    move_seg_to(ref[b], ref[c], begin);
}

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;
    scanf("%d%d", &n, &m);
    struct node *begin, *end;
    init_list(&begin, &end);
    for (int i = 0; i < n; ++i) {
        ref[n-i-1] = mk_node(n-i);
        insert(begin, ref[n-i-1]);
    }
    for (int i = 0; i < m; ++i) {
        int b,c;
        scanf("%d%d", &b, &c);
        --b; --c;
        proceed(begin, end, b, c);
    }
    begin = begin->r;
    while (begin != end) {
        printf("%d ", begin->val);
        begin = begin->r;
    }
    printf("\n");
    return 0;
}
