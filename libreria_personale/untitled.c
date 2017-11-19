#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct int_list {
	int info;
	struct int_list* next; 
} *int_list;


int prepend(int_list *pl, int elem) 
{
	int_list nuova = (int_list)malloc(sizeof(struct int_list));
	if (nuova) {
		nuova->info = elem;
		nuova->next = *pl;
		*pl = nuova;
		return 1;
	}
	else {
		return 0;
	}
}

void stampa_lista_iter(int_list l) 
{ //stampo iterativamente la lista
	while(l) {
		printf("%d\n", l->info);
		l = l->next;
	}
}

int sequenze_counter(int_list l) {
	int elem = 0;
	int first_elem = l->info;
	int size = 1;

	while(l) {
		elem = l->info;

		if (elem != first_elem) {
			size++;
			first_elem = elem;
		}
		l = l->next;
	}
	return size;
}

void comprimi(int_list l, int** vet, int* size) {
	*vet = 0;
	*vet = malloc(sizeof(int*) * (*size));

	if (!(*vet)) {
		printf("Questo non dovrebbe succedere!\n");
	}

	int first_elem = l->info;
	int elem = 0;
	int len = 0;
	int index = 0;
	int diff = 0;

	while (l) {
		elem = l->info;
		if (first_elem == elem) {
			len++;
		}

		else if (first_elem != elem) {
			if (first_elem == 0) {
				diff = 0 - len;
				printf("DIFF %d\n", diff);
				*vet[index] = diff;
			}
			else if (first_elem == 1) {
				printf("LEN %d\n", len);
				*vet[index] = len;
			}
			index++;
			first_elem = elem;
			len = 1;
		}
		l = l->next;
	}
}

int main(int argc, char const *argv[])
{
	int_list l = NULL;
	int *vet = NULL;
	int elem = 0;
	int size = 0;

	prepend(&l, 1);
	prepend(&l, 1);
	prepend(&l, 1);
	prepend(&l, 1);
	prepend(&l, 0);
	prepend(&l, 0);
	prepend(&l, 0);
	prepend(&l, 1);
	prepend(&l, 1);
	prepend(&l, 0);
	prepend(&l, 0);

	stampa_lista_iter(l);

	size = sequenze_counter(l);
	comprimi(l,&vet,&size);
	printf("---------------------\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n",vet[i]);
	}


	return 0;
}