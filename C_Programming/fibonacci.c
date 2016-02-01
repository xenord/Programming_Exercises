#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int info;
    struct nodo* next;
};

typedef struct nodo* list;

inserimentoTesta(int elem, list* l) {
    list tmp;
    tmp = malloc(sizeof(struct nodo));
    tmp->next = *l;
    tmp->info = elem;
    *l = tmp;
    }

int main () {
    list tmp;
    while (tmp->next != NULL) {

    }
}
