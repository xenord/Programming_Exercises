#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


struct node{
	/**/
	struct node* p;
	struct node* left;
	struct node* right;
	int key;
};

typedef struct node *Node;

struct tree{
	Node root;
};

typedef struct tree *BinarySearchTree;

BinarySearchTree new_tree();
Node new_node(int key);
int tree_empty(BinarySearchTree t);
void tree_insert(BinarySearchTree t, Node z);
Node tree_search(Node x, int k);
Node tree_minimum(Node x);
Node tree_successor(Node x);
void tree_delete(BinarySearchTree t, Node z);
void BreadthFirstSearch(Node n);

#endif

