#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

struct node {
    int a, k;
    struct node *next;
};

void error(const char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

void syntax_error(int pos, char c, const char *valid) {
    if (c != 13 && c != 10) printf("Syntax error at position %d: Symbols {%s} excepted but '%c'[%d] found\n", pos, valid, c, c);
    else printf("Syntax error at position %d: Symbols {%s} excepted but new line found\n", pos, valid);
    exit(1);
}

struct node* lstcpy(struct node *list) {
    if (!list) return 0;
    struct node *foo = (struct node *) malloc(sizeof(struct node));
    foo->a = list->a;
    foo->k = list->k;
    foo->next = 0;
    return foo;

}

char TERM = '\n';

struct node* insert(struct node *list, int k, int a) {
    if (a == 0) {
        static const char *err = "Multipliers must be nonzero";
        error(err);
    }
    if (!list) {
        struct node *foo = (struct node *) malloc(sizeof(struct node));
        foo->a = a;
        foo->k = k;
        foo->next = 0;
        return foo;
    }
    if (k > list->k) {
        struct node *foo = (struct node *) malloc(sizeof(struct node));
        foo->a = a;
        foo->k = k;
        foo->next = list;
        return foo;
    } else if (k == list->k) {
        char err[100];
        sprintf(err, "At least two monominals with power %d", k);
        error(err);
    } else {
        list->next = insert(list->next, k, a);
        return list;
    }
}

void free_list(struct node *list) {
    if (!list) return;
    free_list(list->next);
    free(list);
}

struct node* scan(void) {
    struct node *list = 0;
    char state = 'A';
    char c;
    int a; int sgn; int k;
    int pos = 0;
    while (state != 'Z') {
        c = getc(stdin);
        ++pos;
        switch (state) {
            case 'A': {
                static const char *valid = "-0123456789X";
                sgn = 1; k = 0; a = 0;
                if (c == '0') {
                    state = 'B';
                    break;
                }
                if (c == '-') {
                    sgn = -1;
                    state = 'D';
                    break;
                }
                if (c == 'X') {
                    a = 1; k = 1;
                    state = 'E';
                    break;
                }
                if (isdigit(c)) {
                    state = 'C';
                    a = c - '0';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'B': {
                static const char *valid = "\\n0123456789X";
                if (c == TERM) {
                    state = 'Z';
                    break;
                }
                if (isdigit(c)) {
                    a = c - '0';
                    state = 'C';
                    break;
                }
                if (c == 'X') {
                    a = 0; k = 0;
                    state = 'E';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'C': {
                static const char *valid = "\\n0123456789X+-";
                if (c == TERM) {
                    list = insert(list, 0, sgn*a);
                    state = 'Z';
                    break;
                }
                if (c == 'X') {
                    k = 1;
                    state = 'E';
                    break;
                }
                if (isdigit(c)) {
                    a = 10*a + c - '0';
                    break;
                }
                if (c == '+') {
                    list = insert(list, 0, sgn*a);
                    state = 'H';
                    sgn = 1;
                    break;
                }
                if (c == '-') {
                    list = insert(list, 0, sgn*a);
                    state = 'H';
                    sgn = -1;
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'D': {
                static const char *valid = "\\nX";
                if (isdigit(c)) {
                    a = c - '0';
                    state = 'C';
                    break;
                }
                if (c == 'X') {
                    state = 'E';
                    k = 1; a = 1;
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'E': {
                static const char *valid = "\\n^+-";
                if (c == TERM) {
                    list = insert(list, 1, sgn*a);
                    state = 'Z';
                    break;
                }
                if (c == '^') {
                    state = 'F';
                    break;
                }
                if (c == '+') {
                    list = insert(list, 1, sgn*a);
                    sgn = 1;
                    state = 'H';
                    break;
                }
                if (c == '-') {
                    list = insert(list, 1, sgn*a);
                    sgn = -1;
                    state = 'H';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'F': {
                static const char *valid = "0123456789";
                if (isdigit(c)) {
                    k = c - '0';
                    state = 'G';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'G': {
                static const char *valid = "\\n0123456789+-";
                if (isdigit(c)) {
                    k = 10*k + c - '0';
                    break;
                }
                if (c == TERM) {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, sgn*a);
                    state = 'Z';
                    break;
                }
                if (c == '+') {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, sgn*a);
                    sgn = 1;
                    state = 'H';
                    break;
                }
                if (c == '-') {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, sgn*a);
                    sgn = -1;
                    state = 'H';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'H': {
                static const char *valid = "X0123456789";
                k = 0; a = 0;
                if (c == 'X') {
                    state = 'I';
                    a = 1;
                    break;
                }
                if (isdigit(c)) {
                    state = 'J';
                    a = c - '0';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'I': {
                static const char *valid = "\\n+-^";
                if (c == TERM) {
                    list = insert(list, 1, sgn*a);
                    state = 'Z';
                    break;
                }
                if (c == '+') {
                    list = insert(list, 1, sgn*a);
                    sgn = 1;
                    state = 'H';
                    break;
                }
                if (c == '-') {
                    list = insert(list, 1, sgn*a);
                    sgn = -1;
                    state = 'H';
                    break;
                }
                if (c == '^') {
                    state = 'K';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'J': {
                static const char *valid = "\\nX0123456789+-";
                if (isdigit(c)) {
                    a = a*10 + c - '0';
                    break;
                }
                if (c == 'X') {
                    state = 'I';
                    k = 1;
                    break;
                }
                if (c == TERM) {
                    state = 'Z';
                    list = insert(list, 0, sgn*a);
                    break;
                }
                if (c == '+') {
                    list = insert(list, 0, sgn*a);
                    sgn = 1;
                    state = 'H';
                    break;
                }
                if (c == '-') {
                    list = insert(list, 0, sgn*a);
                    sgn = -1;
                    state = 'H';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'K': {
                static const char *valid = "0123456789";
                if (isdigit(c)) {
                    k = c - '0';
                    state = 'L';
                    break;
                }
                syntax_error(pos, c, valid);
            }
            case 'L': {
                static const char *valid = "\\n+-0123456789";
                if (c == TERM) {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, a*sgn);
                    state = 'Z';
                    break;
                }
                if (isdigit(c)) {
                    k = 10*k + c - '0';
                    break;
                }
                if (c == '+') {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, a*sgn);
                    state = 'H';
                    sgn = 1;
                    break;
                }
                if (c == '-') {
                    if (k < 2) error((char *)"Powers should be at least 2");
                    list = insert(list, k, a*sgn);
                    state = 'H';
                    sgn = -1;
                    break;
                }
                syntax_error(pos, c, valid);
            }
        }
    }
    return list;
}

struct node* print(struct node *list) {
    struct node *root = list;
    if (!list) {
        printf("0\n"); return 0;
    }
    int first = 1;
    while (list) {
        if (list->a > 0) {
            if (!first) printf("+");
            if (list->a > 1 || list->k == 0) printf("%d", list->a);
        }
        if (list->a < 0) {
            printf("-");
            if (list->a < -1 || list->k == 0) printf("%d", -list->a);
        }
        if (list->k > 0) printf("X");
        if (list->k > 1) printf("^%d", list->k);
        list = list->next;
        first = 0;
    }
    printf("\n");
    return root;
}

struct node* sum(struct node *l1, struct node *l2) {
    struct node *ans = 0;
    if (!l1 && !l2) return 0;
    if (!l1) return insert(sum(l1, l2->next), l2->k, l2->a);
    if (!l2) return insert(sum(l1->next, l2), l1->k, l1->a);
    if (!l2) return l1;
    if (l1->k > l2->k) return insert(sum(l1->next, l2), l1->k, l1->a);
    if (l1->k < l2->k) return insert(sum(l2->next, l1), l2->k, l2->a);
    if (l1->a + l2->a) 
        return insert(sum(l1->next, l2->next), l1->k, l1->a + l2->a);
    else 
        return sum(l1->next, l2->next);
}

void variant_info(void) {
    printf("lab02 v0.0.4, Mingalev Oleg 2014\n\n");
    printf("Use lab02 -h to see help page\n\n");
    printf("Variant: 16\n");
    printf("Sum of two polynomials\n");
    printf("================================\n");
}

void help(void) {
    printf("lab02 v0.0.4, Mingalev Oleg 2014\n");
    printf("Usage: lab02 [-h]\n\n");
    printf("Polynomial format:");
    printf("<expr> ::= [+|-]<mono>((+|-)<mono>)*\n");
    printf("<mono> ::= <int> | [<int>]X[^<int>]\n");
    printf("<int>  ::= (0..9)+\n");
    printf("All multipliers must be nonzero\n");
    printf("All powers should be at least 2\n");
    printf("To specify zero polynomial just enter 0");
    exit(0);
}

int main(int argc, char *argv[]) {
    variant_info();
    char cur;
    while ((cur = getopt(argc, argv, "hrtv")) != -1) {
        switch (cur) {
            case 'h': case '?': help(); break;
        }
    }
    printf("1st poly: "); fflush(stdout); struct node *l1 = scan();
    printf("2nd poly: "); fflush(stdout); struct node *l2 = scan();
    struct node *ls = sum(l1, l2);
    printf("Sum: "); print(ls);
    free_list(l1); free_list(l2); free_list(ls);
    return 0;
}
