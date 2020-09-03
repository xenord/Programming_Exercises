 <#include <stdio.h>
#include <stdlib.h>
#include "MaxHeap.h"

MaxHeap new_heap(int size) 
{
	MaxHeap a = NULL;
	a = malloc(sizeof(struct maxheap));
	a->heapsize = 0;
	a->data = (int *)malloc(sizeof(int)*size);
	return a;
}

void maxheap_insert(MaxHeap a, int k)
{
	a->heapsize++;
	a->data[a->heapsize] =  k - 1;
	maxheap_increase_key(a, a->heapsize - 1, k);
}

int parent(int index) 
{
	return index / 2;
}

int left(int index)
{
	return 2 * index;
}

int right(int index)
{
	return (2 * index) + 1;
}

void maxheap_increase_key(MaxHeap a, int i, int k)
{
	if (k > *(a->data + i)) {
		a->data[i] = k;
		while (i > 1 && *(a->data + i) > *(a->data + parent(i))) {
			int tmp = *(a->data + i);
			a->data[i] = *(a->data + parent(i));
			a->data[parent(i)] = tmp;
			i = parent(i);
		}
	}
}

int maxheap_maximum(MaxHeap a)
{
	if (a->heapsize < 1) {
		printf("error [maxheap_maximum] MaxHeap overflow");
	}
	return a->data[0];
}

int maxheap_extract_max(MaxHeap a)
{
	int max = a->data[0];

	if (a->heapsize < 1) {
		printf("error [maxheap_extract_max] MaxHeap overflow");
	}

	a->data[1] = a->data[a->heapsize -1];
	a->heapsize = a->heapsize - 1;
	return max;
}

void max_heapify(MaxHeap a, int i)
{
	int l = left(i);
	int r = right(i);
	int massimo = i;

	if (l <= a->heapsize && a->data[l] > a->data[i]) {
		massimo = l;
	}

	if (r <= a->heapsize && a->data[r] > a->data[i]) {
		massimo = r;
	}

	if (massimo != i) {
		int tmp = *(a->data + i);
		a->data[i] = *(a->data + massimo);
		a->data[massimo] = tmp;
		max_heapify(a, massimo);
	}
}

int isMaxHeap(MaxHeap a)
{
	int i;

	for(i=0; i<a->heapsize; i++){
		if(2*i<=a->heapsize && a->data[i]<a->data[2*i])
			return 0;
		if(2*i+1<=a->heapsize && a->data[i]<a->data[2*i+1])
			return 0;
	}
	return 1;
}
