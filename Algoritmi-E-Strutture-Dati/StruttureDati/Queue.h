#ifndef QUEUE_H
#define QUEUE_H

struct node{
	int key;
	struct node * next;
};

typedef struct node * QNode;

struct queue{
	QNode head;
	QNode tail;
	int size;
};

typedef struct queue *Queue;

Queue initqueue();
int emptyqueue(Queue q);
void enqueue(Queue q, int elem);
QNode dequeue(Queue q);
int first(Queue q);
int size(Queue q);

#endif