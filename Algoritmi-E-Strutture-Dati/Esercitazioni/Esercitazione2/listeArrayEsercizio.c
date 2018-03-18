#include <stdio.h>
#include <stdlib.h>
#define DIM 100
#include "list.h"


/*Rappresentazione di liste con array */
typedef struct{ 
  int key[DIM];
  int next[DIM];
  int prev[DIM];
} Spazio;

/* Variabili globali*/
List freeList;  /*Testa della free List che e' una lista DOPPIAMENTE concatenata*/
Spazio space; /*Spazio utilizzato per memorizzare le liste*/


/*Post: inizializza space in modo che tutti gli elementi siano nella lista libera. La testa della lista libera sara' 0 */
void initFreelist(){

}

/*Post: restituisce un oggetto libero. Se lo spazio e' esaurito stampa un messaggio di errore  */
List allocateObject(){ 
  return -1;
}

/*Post: rende libero l'oggetto x  */
void freeObject(List x){

}

/*Post: legge una sequenza di interi inseriti dall'utente (0 per terminare) e restituisce una lista contenente tale sequenza*/
List caricamento(){
  return -1;
}

/* Post: restituisce il numero di elementi contenuti nella lista */
int lunghezza(List l){
  return -1;
}


/*Pre: Si assuma che space abbia m elementi, l sia una lista di n elementi e i rimanenti elementi di space (m -n) siano nella lista libera.
  Post: sposta gli elementi in l in modo che occupino le posizioni 0, 1, ..., n-1 di space e aggiusta la lista libera in modo che essa resti corretta, occupando le posizioni di space n, n+1, ...., m - 1. La funzione restituisce la lista l con gli elementi nelle posizioni specificate.
  Il tempo di esecuzione della funzione e' theta(n) e deve utilizzare SOLO una quantita' costante di spazio extra. */
List compatifyList(List l){
  return -1;
}

/*Post: stampa il contenuto della lista.  */
void stampa(List l){

}

/*Post: dealloca gli elementi contenuti nella lista */
void rimuovi(List l){

}

