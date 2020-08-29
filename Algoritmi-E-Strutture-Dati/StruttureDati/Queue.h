#ifndef QUEUE_H
#define QUEUE_H

typedef struct qnode{
	Node node;
	struct qnode * next;
} qnode;

typedef struct qnode * QNode;

struct queue{
	QNode head;
	QNode tail;
	int size;
}queue;

typedef struct queue *Queue;

Queue initqueue();
int emptyqueue(Queue q);
void enqueue(Queue q, Node elem);
QNode dequeue(Queue q);
Node first(Queue q);
int size(Queue q);

#endif
