#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_list.h"

int append(string_list *sl, char* s) 
{
	string_list l = (string_list)malloc(sizeof(struct string_list));
	if (sl != NULL) {
		l->next = *sl;
		l->str = (char *)malloc(strlen(s)+1);
		if (l->str == NULL) {
			free(l);
			return 0;
		}
		else {
			strcpy(l->str, s);
			*sl = l;
			return 1;
		}
	}	
	else {
		return 0;
	}
}


void frequent_character(string_list sl) 
{
	int i=0;
	string_list tmp = sl;
	char* alphabet = (char*)malloc(sizeof(int)*27);
	int* counter = (int*)malloc(sizeof(int)*27);
	char s = 'a';

	for (i = 0; i < 27; i++)
	{
		alphabet[i] = s;
		s++;
		if (i == 26) {
			alphabet[i] = '\0';
		}
	}

	int index = 0;
	i=0;
	int flag = 0;


	while (alphabet[index] != '\0') {
		flag = 0;
		i=0;
		while (sl) {
			while (sl->str[i] != '\0') {
				printf("Analizzo: %c\n", sl->str[i]);
				if (sl->str[i] == alphabet[index]) {
					flag=1;
				}
				i++;
			}
			if (flag == 1) {
				counter[index] = 1;
			}
			else {
				counter[index] = 0;
				index++;
			}
			sl = sl->next;
		}
		index++;
		sl = tmp;
	}

	i=0;
	while (alphabet[i] != '\0') {
		if (counter[i] == 1) {
			printf("%c\n", alphabet[i]);
		}
		i++;
	}
	free(counter);
	free(alphabet);
}
