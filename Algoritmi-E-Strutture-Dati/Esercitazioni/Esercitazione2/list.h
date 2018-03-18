#ifndef LIST_H
#define LIST_H

typedef int List;

void initFreelist();
List allocateObject();
void freeObject(List x);
List caricamento();
int lunghezza(List l);
List compatifyList(List l);
void stampa(List l);
void rimuovi(List l);

#endif

