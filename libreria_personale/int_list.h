#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct int_list {
	int info;
	struct int_list* next; 
} *int_list;

#endif


#ifndef INT_LIST_FUNZIONI_H
#define INT_LIST_FUNZIONI_H

void stampa_lista_rec(int_list l);
void stampa_lista_iter(int_list l);
int prepend(int_list *pl, int elem);
int append(int_list *pl, int elem);

#endif
