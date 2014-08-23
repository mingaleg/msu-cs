#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int cnt;
    struct node *go[27];
    unsigned char *edge[27];
};

struct node * mk_node(void) {
    struct node *foo = (struct node *) malloc(sizeof(struct node));
    foo->cnt = 0;
    for (int i = 0; i < 27; ++i) {
        foo->go[i] = 0;
        foo->edge[i] = 0;
    }
    return foo;
}

void mystrcpy(unsigned char **dest, unsigned char *src) {
    *dest = (unsigned char *) realloc(*dest, (strlen(src)+1)*sizeof(unsigned char));
    strcpy(*dest, src);
}

void insert(struct node *root, unsigned char *s) {
    if (!*s) return;
    unsigned char fc = *s;
    if (!root->go[fc]) {
        root->go[fc] = mk_node();
        mystrcpy(&root->edge[fc], s);
        return;
    }
    unsigned char *foo = s;
    while (*foo && root->edge[fc][foo-s] == *foo) {
        ++foo;
    }
    if (!*foo) return;
    if (root->edge[fc][foo-s]) {
        struct node *bar = mk_node();
        struct node *baz = mk_node();
        bar->go[*foo] = baz;
        mystrcpy(&bar->edge[*foo], foo);
        bar->go[root->edge[fc][foo-s]] = root->go[fc];
        mystrcpy(&bar->edge[root->edge[fc][foo-s]], root->edge[fc]+(foo-s));
        int newlen = foo-s;
        root->edge[fc] = (unsigned char *) realloc(root->edge[fc], (newlen+1)*sizeof(unsigned char));
        root->edge[fc][newlen] = 0;
        root->go[fc] = bar;
    } else {
        insert(root->go[fc], foo);
    }
}

void fill(struct node *root, unsigned char *str) {
    if (!root) return;
    if (!*str) return;
    unsigned char tc = *str;
    if (!root->edge[tc]) return;
    unsigned char *foo = str;
    int cans = 0;
    while (*foo && root->edge[tc][cans] && root->edge[tc][cans] == *foo) {
        ++foo; ++cans;
    }
    if (cans > root->go[tc]->cnt) root->go[tc]->cnt = cans;
    if (!root->edge[tc][cans]) fill(root->go[tc], foo);
}

int answer(struct node *root) {
    if (!root) return 0;
    int ans = root->cnt;
    for (int i = 0; i < 27; ++i) ans += answer(root->go[i]);
    return ans;
}

void debug_tree(struct node *root, unsigned char *edge, int level) {
    for (int i = 0; i < level; ++i) printf("  ");
    printf("=");
    for (char *foo = edge; *foo; ++foo) printf("%c", *foo+'a'-1);
    printf("= %d\n", root->cnt);
    /*printf("=%s=\n", edge);*/
    for (int i = 0; i < 27; ++i) {
        if (!root->go[i]) continue;
        debug_tree(root->go[i], root->edge[i], level+1);
    }
}

int main(void) {
    struct node *root = mk_node();
    /*char *test[6] = {"abcd", "bcdd", "abce", "a", "bca", "abcde"};
    for (int i = 0; i < 6; ++i) {
        printf("+++ %s\n", test[i]);
        insert(root, test[i]);
        debug_tree(root, "", 0);
        printf("\n");
    }*/
    char t1[4001], t2[4001];
    scanf("%s%s", t1, t2);
    for (char *foo = t1; *foo; ++foo) *foo -= 'a'-1;
    for (char *foo = t2; *foo; ++foo) *foo -= 'a'-1;
    for (char *foo = t1; *foo; ++foo) insert(root, foo);
    for (char *foo = t2; *foo; ++foo) fill(root, foo);
    /*debug_tree(root, "", 0);*/
    printf("%d\n", answer(root)+1);
    return 0;
}
