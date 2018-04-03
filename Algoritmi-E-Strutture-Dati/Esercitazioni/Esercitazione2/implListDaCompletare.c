#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listStringhe.h"

/*
Con esclusione della funzione search e della procedura intersezione, 
le altre funzioni devono avere complessità in tempo costante. 
Calcolare la complessità per search e intersezione, 
assumendo che le funzioni delle librerie string.h e stdlib.h siano costanti.
*/

/*post: restituisce una lista vuota */
List crealista(){
	List l;
	l = (List) malloc(sizeof(struct list));
  	l->head = NULL;
  	return l;
}

/*post: restituisce 1 se l e' vuota, 0 altrimenti. */
int listEmpty(List l){
	if (l->head == NULL) {
		return 1;
	}
	return 0;
}

void stampa_string(Node n) {
	int i=0;

	while(n->key[i] != '\0') {
		printf("%c", n->key[i]);
		i++;
	}
}

/*post: restituisce 1 se il nodo n e' il FINELISTA (puo' essere la costante NULL oppure il nodo sentinella a seconda della scelta implementativa), altrimenti 0*/
int finelista(List l, Node n){
	if (n->next == NULL) {
		return 1;
	}
	return 0;
}

/*post: restituisce l'ultimo nodo con chiave k, se esiste, altrimenti il FINELISTA */
Node search(List l, char * k){
	Node x = l->head;
	Node cmp = NULL;

	while (x != NULL) {
		if (strcmp(x->key, k) == 0) {
			cmp = x;
		}
		x = x->next;
	}

	if (cmp != NULL) {
		return cmp;
	}
	return NULL;
}

/*pre: se x non e' il FINELISTA x e' un nodo della lista */
/*post: 
  se x non e' il FINELISTA inserisce un nodo con chiave k nella lista come predecessore del nodo x, 
  altrimenti inserisce un nodo con chiave k come ultimo elemento della lista. 
  Restituisce il nodo creato*/
Node insert(List l, Node x, char * k){
	/*
	x->next = l->head;
	x->key = k;

	if (l->head != NULL) {
		l->head->prev = x;
	}

	l->head = x;
	x->prev = NULL;
	*/
	Node n = NULL;
	n = (Node)malloc(sizeof(struct node));
	n->key = k;
	
	if (finelista(l, x)) {
		x->next = n;
		n->prev = x;
		if (l->head == NULL) {
			l->head = n;
		}
	}
	else {
		Node tmp = x;
		if (x->prev == NULL) {
			l->head = n;
		}
		x->prev = n;
		n->prev = tmp->prev;
		n->next = x;
	}
	return n;
}

/*pre: x e' un nodo della lista, NON e' il FINELISTA */
/*post: cancella il nodo x dalla lista */
void delete(List l, Node x){
	Node n = l->head;
	while (strcmp(n->key, x->key) != 0) {
		n = n->next;
	}

	Node tmp = n;
	n = n->prev;
	n->next = NULL;
	free(tmp);
}

/*	CUSTOM
	pre: lista non vuota
	post: cancella l'ultimo nodo dalla lista
*/
void deleteLast(List l) {
	Node n = l->head;

	while(n->next->next != NULL) {
		n = n->next;
	}

	Node tmp = n->next;
	n->next = NULL;

	free(tmp);
}



/*pre: n e' un nodo della lista, NON e' il FINELISTA */
/*post: restituisce il valore contenuto nel nodo della lista */
char * leggilista(List l, Node n){
	return NULL;
}

/*pre: n e' un nodo della lista, NON e' il FINELISTA */
/*post: modifica il valore contenuto nel nodo n con il valore k */
void scrivilista(List l, Node n, char * k){

}

/*post: restituisce il primo nodo della lista se la lista e' non vuota o
il FINELISTA se e' vuota */
Node primolista(List l){
	return NULL;
}

/*pre: n e' un nodo della lista, NON e' il FINELISTA */
/*post: restituisce il nodo successivo al nodo n */
Node succlista(List l, Node n){
	return NULL;
}

/*pre: n e' un nodo della lista, NON e' il FINELISTA */
/*post: restituisce il nodo predecessore al nodo n */
Node predlista(List l, Node n){
	return NULL;
}

/*post: restituisce una lista che e' ottenuta concatenando la lista l2 in fondo alla lista l1. Le liste l1 e l2 sono distrutte dall'operazione. */
List concatena(List l1, List l2){
	return NULL;
} 

/*pre: l1 e' ordinata in modo crescente e l2 ordinata in modo decrescente */
/*post: modifica l1 in modo che sia l’intersezione fra l1 e l2, ordinata in modo crescente, tenendo conto anche della molteplicità delle occorrenze. */
void intersezione(List l1, List l2){

}

void stampa_lista(List l) {
	Node n = l->head;
	int i;
	while(n) {
		i = 0;
		while (n->key[i] != '\0') {
			printf("%c", n->key[i]);
			i++;
		}
		printf("\n");
		n = n->next;
	}	
}

void distruggi_list(List l) {
	Node head = l->head;
	while (head) {
		Node tmp = head->next;
		free(head);
		head = tmp;
	}

	free(l);
}