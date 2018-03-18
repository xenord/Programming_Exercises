#include <stdio.h>
#include <stdlib.h>

#include "listStringhe.h"


int main(int argc, char const *argv[])
{
	List l = crealista();
	Node n = NULL;
	Node new = NULL;
	char greeter[] = "testa";
	n = (Node)malloc(sizeof(struct node));
	n->key = greeter;
	l->head = n;

	char k[] = "ciao";
	new = insert(l, n, k);
	
	stampa_lista(l);

	printf("\n");

	printf("DELETE\n");
	delete(l, new);

	stampa_lista(l);

	//stampa_lista(l);
	return 0;
}
