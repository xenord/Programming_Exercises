#ifndef LISTSTRINGHE_H
#define LISTSTRINGHE_H


struct node{
	/**/
	struct node* next;
	struct node* prev;
	char* key;
};

typedef struct node *Node;

struct list{
	Node head;
};

typedef struct list *List;

List crealista();
int listEmpty(List l);
int finelista(List l, Node n);
Node search(List l, char * k);
Node insert(List l, Node x, char * k);
void delete(List l, Node x);
char * leggilista(List l, Node n);
void scrivilista(List l, Node n, char * k);
Node primolista(List l);
Node succlista(List l, Node n);
Node predlista(List l, Node n);
List concatena(List l1, List l2);
void intersezione(List l1, List l2);
void stampa_lista(List l);
void deleteLast(List l);
void distruggi_lista(List l);

#endif

