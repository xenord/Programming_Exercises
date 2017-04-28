#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"


void stampa_lista_rec(int_list l) 
{ //stampo ricorsivamente la lista
	if (l) {
		printf("%d\n", l->info);
		stampa_lista_rec(l->next);
	}
}

void stampa_lista_iter(int_list l) 
{ //stampo iterativamente la lista
	while(l) {
		printf("%d\n", l->info);
		l = l->next;
	}
}

int prepend(int_list *pl, int elem) 
{
	int_list nuova = (int_list)malloc(sizeof(struct int_list));
	if (nuova) {
		nuova->info = elem;
		nuova->next = *pl;
		*pl = nuova;
		return 1;
	}
	else {
		return 0;
	}
}

int append(int_list *pl, int elem) 
{
	if (*pl == NULL) {
		return prepend(pl, elem);
	}
	else {
		return append(&((*pl)->next) ,elem);
	}
}


