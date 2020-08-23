#ifndef QUEUE_H
#define QUEUE_H

struct qnode{
	Node key;
	struct qnode * next;
};

typedef struct qnode * QNode;

struct queue{
	QNode head;
	QNode tail;
	int size;
};

typedef struct queue *Queue;

Queue initqueue();
int emptyqueue(Queue q);
void enqueue(Queue q, Node elem);
QNode dequeue(Queue q);
Node first(Queue q);
int size(Queue q);

#endif
