//
// Created by Francesco Benetello on 21/08/17.
//


#ifndef CHAR_LIST_H
#define CHAR_LIST_H

typedef struct char_list {
    char info;
    struct char_list* next;
} *char_list;

#endif

#ifndef EXERCISES_CHAR_LIST_H
#define EXERCISES_CHAR_LIST_H
int prepend(char_list *l, char elem);
int append(char_list* l, char elem);
void rimuovi_a(char_list l);
void print_list_rec(char_list l);
void free_list(char_list l);

#endif //EXERCISES_CHAR_LIST_H
