#include <stdio.h>
#include <stdlib.h>

typedef struct char_list {
    char info;
    struct char_list* next;
} *char_list;


int prepend(char_list *l, char elem)
{
    char_list nuova = (char_list)malloc(sizeof(struct char_list));
    if (nuova) {
        nuova->info = elem;
        nuova->next = *l;
        *l = nuova;
        return 1;
    }
    else {
        return 0;
    }
}

int append(char_list* l, char elem)
{
    if (*l == NULL) {
        return prepend(l, elem);
    }
    else {
        return append(&((*l)->next), elem);
    }
}

void rimuovi_a(char_list l)
{
    char_list l2;

    while (l != NULL) {
        if ((l->info == 'a') || (l->info == 'A')) {
            l2 = l;
            free(l2);
        }
        l = l->next;
    }
}

void print_list_rec(char_list l) 
{
    if (l) {
        printf("%c\n", l->info);
        print_list_rec(l->next);
    }

}

void free_list(char_list l) 
{
    char_list l2;
    while (l) {
        l2 = l->next;
        free(l);
        l = l2;
    }
}