#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

int main(int argc, char const *argv[])
{
	int_list lista;
	int_list lista2;
	lista = NULL;
	int len = 0;

	prepend(&lista, 1);
	prepend(&lista, 2);
	prepend(&lista, 3);

	stampa_lista_iter(lista);
	len = lstlen(lista);
	printf("Lunghezza = %d\n", len);

	lstcpy(lista, &lista2);
	printf("Stampo lista due\n");
	stampa_lista_iter(lista2);

	free(lista);
	free(lista2);


	return 0;
}