#ifndef INT_LIST_H
#define INT_LIST_H

typedef struct string_list {
	char* str;
	struct string_list* next; 
} *string_list;

#endif


#ifndef INT_LIST_FUNZIONI_H
#define INT_LIST_FUNZIONI_H

int append(string_list *sl, char* string);
void frequent_character(string_list sl);

#endif