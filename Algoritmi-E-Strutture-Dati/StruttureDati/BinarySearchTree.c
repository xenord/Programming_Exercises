#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "Queue.h"

BinarySearchTree new_tree() 
{
	BinarySearchTree t = NULL;
	t = malloc(sizeof(struct tree *));
	printf("Tree address: %p\n", (void*)t);
	t->root = NULL;
	return t;
}

Node new_node(int key) 
{
	Node n = NULL;
	n = malloc(sizeof(struct node *));
	printf("Node address: %p\n", (void*)n);
	printf("Save this %d\n", key);
	n->key = key;
	n->p = NULL;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int tree_empty(BinarySearchTree t) 
{
	if (t->root == NULL) {
		return 1;
	}
	return 0;
}

void tree_insert(BinarySearchTree t, Node z)
{
	Node y = NULL;
	Node x = t->root;
	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		} else {
			x = x->right;
		}
	}

	z->p = y;
	if (y == NULL) {
		t->root = z;
	} else if (z->key < y->key) {
		y->left = z;
	} else {
		y->right = z;
	}
}

Node tree_search(Node x, int k) 
{
	if (x == NULL || x->key == k) {
		return x;
	} else if (k < x->key) {
		return tree_search(x->left, k);
	} else {
		return tree_search(x->right, k);
	}
}

Node tree_minimum(Node x)
{
	while (x != NULL) {
		x = x->left;
	}
	return x;
}

Node tree_successor(Node x)
{
	if (x->right != NULL) {
		return tree_minimum(x->right);
	} else {
		Node y = x->p;
		while (y != NULL && y->right == x) {
			x = y;
			y = y->p;
		}
		return y;
	}
}

void transplant(BinarySearchTree t, Node u, Node v)
{
	if (u->p == NULL) {
		t->root = v;
	} else if (u == u->p->left) {
		u->p->left = v;
	} else {
		u->p->right = v;
	}

	if (v != NULL) {
		v->p = u->p;
	}
}

void tree_delete(BinarySearchTree t, Node z)
{
	if (z->left == NULL) {
		transplant(t, z, z->right);
	} else if (z->right == NULL) {
		transplant(t, z, z->left);
	} else {
		Node y = tree_minimum(z->right);
		if (y->p != z) {
			transplant(t, y, y->right);
			y->right = z->right;
			z->right->p = y;
		}
		transplant(t, z, y);
		y->left = z->left;
		z->left->p = y;
	}
}

void preorder(Node n)
{
	if (n != NULL) {
		printf("%d\n", n->key);
		printf("Visit Node address: %p\n", (void*)n);
		preorder(n->left);
		preorder(n->right);
	}
}

void BreadthFirstSearch(Node n)
{
	Queue q = initqueue();
	enqueue(q, n);
	while (!emptyqueue(q)) {
		QNode e = dequeue(q);
		if (e != NULL) {
			printf("%d\n", e->key->key);
			if (e->key->left != NULL) {
				enqueue(q, e->key->left);
			}
			if (e->key->right != NULL) {
				enqueue(q, e->key->right);
			}
		}
	}
}
