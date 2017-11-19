#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"


void stampa_lista_rec(int_list l) 
{ //stampo ricorsivamente la lista
	if (l) {
		printf("%d\n", l->info);
		stampa_lista_rec(l->next);
	}
}

void stampa_lista_iter(int_list l) 
{ //stampo iterativamente la lista
	while(l) {
		printf("%d\n", l->info);
		l = l->next;
	}
}

void distruggi_lista(int_list l)
{
	while(l) {
		free(l);
		l = l->next;
	}
}

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

int append(int_list *pl, int elem) 
{
	if (*pl == NULL) {
		return prepend(pl, elem);
	}
	else {
		return append(&((*pl)->next) ,elem);
	}
}

int lstlen(int_list l)
{
	if (l == NULL) {
		return 0;
	}
	else {
		return 1+lstlen(l->next);
	}
}

/*
	l1 -> start list
	l2 -> final list
*/
void lstcpy(int_list l1, int_list l2)
{
	int elem;
	while (l1) {
		elem = l1->info;
		append(&l2,elem);
		l1 = l1->next;
	}
}

/*
 *
 * Date due liste viene creata una terza lista dove vengono alternati
 * gli elementi delle due liste, se una lista è più corta dell'altra
 * allora verranno aggiunti gli elementi della lista più lunga
 *
 */

int_list mix(int_list l1, int_list l2) 
{
	int len1=0, len2=0;
	len1 = lstlen(l1);
	len2 = lstlen(l2);
	int_list l3=NULL;

	if (len1 > len2) {
		while (l2) {
			append(&l3, l1->info);
			l1 = l1->next;
			append(&l3, l2->info);
			l2 = l2->next;
		}
		while (l1) {
			append(&l3, l1->info);
			l1 = l1->next;
		}
	}
	else if (len2 > len1) {
		while (l1) {
			append(&l3, l1->info);
			l1 = l1->next;
			append(&l3, l2->info);
			l2 = l2->next;
		}
		while (l2) {
			append(&l3, l1->info);
		}	

	}

	return l3;
}

int test_quiz_1(int_list l) 
{
	if (l && l->next) {
		return (l->info % 2 == 1) ? 1*test_quiz_1(l->next) : 2*test_quiz_1(l->next);
	}
	else {
		return 1;
	}

}

int_list set_zero_before_seven(int_list l)
{
	if (l == NULL) {
		return NULL;
	}
	else if (l->next == NULL) {
		return l;
	}
	else if (l->next->next == NULL) {
		if (l->info == 7) {
			return l;
		}
		else  {
			l->info = 0;
			return set_zero_before_seven(l->next);
		}
	}
}


