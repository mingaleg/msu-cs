#include<stdio.h>
#include<stdlib.h>

int randoms[500000];
int rused = 0;

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void seed(void) {
    for (int i = 0; i < 500000; ++i) randoms[i] = i;
    rused = 0;
    shuffle(randoms, 500000);
}

struct node {
    int key;
    int prior;
    int val;
    struct node *l, *r;
};

struct node * _mk_node(int key, int val) {
    struct node *foo = (struct node *) malloc(sizeof(struct node));
    foo->l = foo->r = 0;
    foo->key = key; foo->val = val;
    foo->prior = randoms[rused++];
    return foo;
}

void _split(struct node *root, int key, struct node **l, struct node **r) {
    if (!root) {
        *l = *r = 0;
        return;
    }
    if (key < root->key) {
        _split(root->l, key, l, &root->l); *r = root;
    } else {
        _split(root->r, key, &root->r, r); *l = root;
    }
}

void _insert(struct node **root, struct node *item) {
    if (!*root) {
        *root = item;
        return;
    }
    if (item->prior > (*root)->prior) {
        _split(*root, item->key, &item->l, &item->r);
        *root = item;
    } else {
        if (item->key < (*root)->key) {
            _insert(&(*root)->l, item);
        } else {
            _insert(&(*root)->r, item);
        }
    }
}

void insert(struct node **root, int key, int val) {
    _insert(root, _mk_node(key, val));
}

void _merge(struct node **root, struct node *l, struct node *r) {
    if (!l) {
        *root = r; return;
    }
    if (!r) {
        *root = l; return;
    }
    if (l->prior > r->prior) {
        _merge(&l->r, l->r, r); *root = l;
    } else {
        _merge(&r->l, l, r->l); *root = r;
    }
}

void delete(struct node **root, int key) {
    if (!*root) return;
    if ((*root)->key == key) {
        _merge(root, (*root)->l, (*root)->r);
    } else {
        if (key < (*root)->key) {
            delete(&(*root)->l, key);
        } else {
            delete(&(*root)->r, key);
        }
    }
}

struct node * search(struct node *root, int key) {
    if (!root) return 0;
    if (root->key == key) return root;
    if (key < root->key) {
        return search(root->l, key);
    } else {
        return search(root->r, key);
    }
}

void let(struct node **root, int key, int val) {
    struct node *foo = search(*root, key);
    if (foo) {
        foo->val = val;
    } else {
        insert(root, key, val);
    }
}

void debug_tree(struct node *root, int level) {
    if (!root) {
        for (int i = 0; i < level; ++i) printf("  ");
        printf("...\n");
        return;
    }
    for (int i = 0; i < level; ++i) printf("  ");
    printf("%d(%d): %d\n", root->key, root->prior, root->val);
    for (int i = 0; i < level; ++i) printf("  ");
    printf("==LEFT==\n");
    debug_tree(root->l, level+1);
    for (int i = 0; i < level; ++i) printf("  ");
    printf("==RIGHT==\n");
    debug_tree(root->r, level+1);
    for (int i = 0; i < level; ++i) printf("  ");
    printf("==END==\n");
}

int main(void) {
    srand(228);
    seed();
    struct node *root = 0;
    while (1) {
        //debug_tree(root, 0);
        char cmd;
        scanf("%1s", &cmd);
        if (cmd == 'F') return 0;
        if (cmd == 'A') {
            int k, v;
            scanf("%d%d", &k, &v);
            let(&root, k, v);
        } else if (cmd == 'D') {
            int k;
            scanf("%d", &k);
            delete(&root, k);
        } else if (cmd == 'S') {
            int k;
            scanf("%d", &k);
            struct node *foo = search(root, k);
            if (foo) {
                printf("%d %d\n", k, foo->val);
            }
        } else {
            printf("BRATISHKA YA TEBE POKUSHAT' PRINES\n");
        }
    }
    return 0;
}
