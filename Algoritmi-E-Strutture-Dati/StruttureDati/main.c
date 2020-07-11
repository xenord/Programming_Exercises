#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(int argc, char const *argv[])
{
	BinarySearchTree t = new_tree();
	printf("%d\n",tree_empty(t));

	Node n = new_node(7);
	tree_insert(t,n);
	printf("%d\n",tree_empty(t));
	tree_delete(t,n);
	printf("%d\n",tree_empty(t));
	return 0;
}