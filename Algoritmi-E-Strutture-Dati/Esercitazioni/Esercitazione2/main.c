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
	
	Node tmp = search(l, k);

	if (tmp == NULL) {
		printf("Non ho trovato nessuna corrispondenza\n");
	}
	else {
		printf("Stringa trovata\n");
	}

	//stampa_lista(l);
	return 0;
}
