#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"
#include "Queue.h"

QNode new(Node k){
	QNode n = NULL;
	n = (QNode) malloc(sizeof(struct qnode*));
	n->key = k;
	n->next = NULL;
	return n;
}

/* post: costruisce una coda vuota */
Queue initqueue()
{
	Queue q;
	q = (Queue) malloc(sizeof(struct queue));
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
	return q;
}

/*post: ritorna 1 se la coda e' vuota, 0 altrimenti */
int emptyqueue(Queue q)
{
  return q->head == NULL;
}

/*post: inserisce elem in coda se la coda non e' piena */
void enqueue(Queue q, Node k)
{
	if (q->head == NULL){
		q->tail = new(k);
		q->head = q->tail;
	} else{
		q->tail->next = new(k);
		q->tail = q->tail->next;  
	}
  	(q->size)++;
}

/*pre: coda non vuota  */
/*post: ritorna e rimuove il primo elemento in coda */
QNode dequeue(Queue q)
{
	QNode ris;
	QNode temp;
	temp = q->head;
	ris = temp;
	q->head = q->head->next;
  	if (temp == q->tail) {
		q->tail = NULL;
    	}
	free(temp);
  	(q->size)--;
	return ris; 
}

Node first(Queue q)
{
  return q->head->key;
}

/*post: ritorna il numero di elementi nella coda */
int size(Queue q)
{
  return q->size;
}
