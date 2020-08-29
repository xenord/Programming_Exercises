#include <stdio.h>
#include <stdlib.h>
#include "StruttureDati/MaxHeap.h"


int main() {
	int i;
	MaxHeap a = new_heap(7);

	maxheap_insert(a, 10);
	maxheap_insert(a, 5);
	maxheap_insert(a, 19);
	maxheap_insert(a, 1);
	maxheap_insert(a, 6);
	maxheap_insert(a, 17);
	maxheap_insert(a, 21);

	for (i = 0; i < a->heapsize; i++) {
		max_heapify(a, i);
	}
	for (i = 0; i < a->heapsize; i++) {
		printf("%d\n", a->data[i]);
	}
	printf("isMaxHeap: %d\n", isMaxHeap(a));
	return 0;
}
