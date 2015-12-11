#include<stdio.h>
#include<stdlib.h>


struct Nodo {
    int info; /* elemento della lista tipo int */
    struct Nodo* next;
};

typedef struct Nodo* list;

int inserimentoTesta (list* l, int elem) {
    list nuovo;
    nuovo = malloc(sizeof(struct Nodo));
    nuovo->info = elem;
    *l->next = nuovo; /* Punta alla nuova cella della lista */; 
    }

int main () {
    list lista;
    creaLista(lista);
    stampaLista(lista);
    return 0;
}
