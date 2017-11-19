#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

int main(int argc, char const *argv[])
{
	int_list lista1;
	int_list lista2;

	lista1 = NULL;

	/*
	append(&lista1, 1000);
	append(&lista1, 20);
	append(&lista1, 15);
	append(&lista1, 2);
	append(&lista1, 3);
	append(&lista1, 4);
	*/

	
	append(&lista1, 1);
	append(&lista1, 2);
	append(&lista1, 3);
	
	stampa_lista_iter(lista1);

	//  MIA RISPOSTA: C
	//  QUELLA CORRETTA: 

	while(lista1 != NULL) {
		int_list tmp = lista1->next;
		free(lista1);
		lista1 = tmp;
	}

	return 0;
}