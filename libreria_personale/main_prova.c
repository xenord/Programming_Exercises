#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "char_list.h"


int main() {
	char_list l = NULL;

	append(&l, 'c');
	append(&l, 'i');
	append(&l, 'a');
	append(&l, 'o');

	rimuovi_a(l);
	print_list_rec(l);

	free_list(l);
	return 0;
}