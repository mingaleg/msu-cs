#include <stdlib.h>

struct Item
{
    struct Item *next;
    struct Info info;
};

struct Item *list;

struct Item*
push_frontal(struct Item *lst, struct Info elem)
{
    struct Item *foo = (struct Item*) malloc(sizeof(struct Item));
    foo->info = elem;
    foo->next = lst;
    return foo;
}

struct Item *list;

void
solve(void)
{
    list = NULL;
    for (int i = 0; i < arr_size; ++i) {
        list = push_frontal(list, arr[i]);
    }
}
