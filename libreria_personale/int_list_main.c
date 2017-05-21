#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

int main(int argc, char const *argv[])
{
	int_list lista;
	lista = NULL;

	prepend(&lista, 1);
	prepend(&lista, 2);
	prepend(&lista, 3);

	stampa_lista_iter(lista);

	free(lista);


	return 0;
}