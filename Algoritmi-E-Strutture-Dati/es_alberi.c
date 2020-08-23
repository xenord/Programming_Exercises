#include <stdio.h>
#include <stdlib.h>
#include "StruttureDati/BinarySearchTree.h"

/*
 Un nodo di un albero binario è detto pari se il numero di foglie del sottoalbero di cui è radice è  pari. 
 a. Progettare un algoritmo efficiente che dato un albero binario restituisca il numero di nodi pari.  
 b. Discutere brevemente la complessità della soluzione trovata.
 La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key. 
*/
void isPariAux(Node x, int * nfoglie) {
	if (x != NULL) {
		isPariAux(x->left, nfoglie);
		isPariAux(x->right, nfoglie);

		if (x->left == NULL && x->right == NULL) {
			*nfoglie = *nfoglie + 1;
		}
	}
}

int isPari(Node x) {
	int nfoglie = 0;
	isPariAux(x, &nfoglie);
	return nfoglie;
}

int main() {
	BinarySearchTree t = new_tree();
	/*Node n = NULL;*/
	tree_insert(t, new_node(7));
	tree_insert(t, new_node(11));
	tree_insert(t, new_node(5));
	tree_insert(t, new_node(6));
	/*n = new_node(7);
	tree_insert(t, n);
	free(n);

	n = new_node(11);
	tree_insert(t, n);
	free(n);

	n = new_node(5);
	tree_insert(t, n);
	free(n);

	n = new_node(6);
	tree_insert(t, n);
	free(n);*/

	/*printf("# foglie: %d\n", isPari(t->root));*/
	
	//preorder(t->root);
	printf("%d\n", t->root->key);
	printf("%d\n", t->root->left->key);
	printf("%d\n", t->root->right->key);
	//printf("Visita in ampiezza:\n");
	//BreadthFirstSearch(t->root);
	return 0;
}
