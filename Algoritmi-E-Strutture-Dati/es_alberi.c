#include <stdio.h>
#include <stdlib.h>
#include "StruttureDati/BinarySearchTree.h"
#include "StruttureDati/Queue.h"

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

/*
Dare la definizione di albero binario completo.
Scrivere in C un programma efficiente per stabilire se un albero binario è completo e calcolarne la complessità al caso pessimo indicando, e risolvendo, la corrispondente relazione di ricorrenza.
*/
int assoluto(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

void n_leaves(Node x, int * n) {
	if (x != NULL) {
		n_leaves(x->left, n);
		n_leaves(x->right, n);
		if (x->left == NULL && x->right == NULL) {
			*n += 1;
		}
	}
}

int isCompleto(Node x) {
	int n = 0;
	n_leaves(x, &n);
	printf("Height: %d\n", tree_height(x));
	return 2*tree_height(x) == n;
}

int main() {
	BinarySearchTree t = new_tree();

	tree_insert(t, new_node(10));
	tree_insert(t, new_node(5));
	tree_insert(t, new_node(19));
	tree_insert(t, new_node(1));
	tree_insert(t, new_node(6));
	tree_insert(t, new_node(17));
	tree_insert(t, new_node(21));

	/*Node n = NULL;

	n = new_node(7);
	printf("%p\n", (void*)n);
	tree_insert(t, n);

	n = new_node(11);
	printf("%p\n", (void*)n);
	tree_insert(t, n);

	n = new_node(5);
	tree_insert(t, n);

	n = new_node(6);
	tree_insert(t, n);*/

	/*printf("# foglie: %d\n", isPari(t->root));*/
	
	/*preorder(t->root);*/

	/*printf("%d\n", t->root->key);
	printf("%d\n", t->root->left->key);
	printf("%d\n", t->root->right->key);*/
	
	printf("isCompleto: %d\n", isCompleto(t->root));
	return 0;
}
