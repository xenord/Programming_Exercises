#ifndef HEAP_H
#define HEAP_H

typedef struct maxheap{
	int * data;
	int heapsize;
} maxheap;

typedef struct maxheap * MaxHeap;

MaxHeap new_heap(int size);
void maxheap_insert(MaxHeap a, int k);
int parent(int index);
void maxheap_increase_key(MaxHeap a, int i, int k);
int maxheap_maximum(MaxHeap a);
int maxheap_extract_max(MaxHeap a);
void max_heapify(MaxHeap a, int i);
int isMaxHeap(MaxHeap a);

#endif
