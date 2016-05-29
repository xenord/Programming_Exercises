/*
 * Author: Francesco Benetello
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mia_libreria.h"

/*
 * Per compilare usare il seguente comando:
 *   gcc -std=gnu89 -Wall -pedantic -o nome_eseguibile file_della_libreria.c file_normale.c
 */


/*
 * rec_fact : calcola il fattoriale con algoritmo ricorsivo
 * Da usare quando: si hanno numeri piccoli, altrimenti diventa inefficiente
 *
 */

unsigned long int rec_fact(unsigned long int n) {  
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
    		return n;
  	}
  	else {
		return n * rec_fact(n-1);
  	}
}

/*
 * iter_fact : calcola il fattoriale con algoritmo iterattivo
 * E' il più conveniente da usare perchè è più efficiente rispetto a quello ricorsivo
 *
 */

unsigned long int iter_fact (unsigned long int n) 
{
	unsigned long int i = n;
	unsigned long int m = 1;
	
	while(i > 0) {
		i--;
		if (i <= 0) {
			return m * n;
		}
		else {
			m = m * i;
		}
	}
	return m * n;
}


/*
 *  1 se s1 è prefisso di s2
 *
 *  0 altrimenti
 *
 *  NOTA BENE: Mac OS X carattere fine stringa: '\n', Linux: '\0'
 *
 */
 
#define DIM 30

int prefisso (char s1[], char s2[])
{
    int i = 0;
    int ris = 1;
    while(ris && s1[i] != '\n' && s2[i] != '\n') {
    		if (s1[i] != s2[i]) {
	        ris = 0;
        }
    		i++;
    }
    if ((ris && s1[i] == '\0') || (ris && s2[i] == '\0')) {
    		ris = 1;
    }
	return ris;
}

/*
 * Funzione per calcolare il MCD (Massimo Comune Divisore)
 * I sottoprogrammi: per trovare il MCD tra 3 numeri a, b, c
 * si può fare il MCD tra a, b e lo chiamiamo d
 * dopodichè richiamiamo la funzione che calcola il MCD tra d e c e la chiamiamo e
 */

int mcd(int x, int y) 
{
	while (x != y) {
		if (x > y) {
			x = x - y;
		}
		else {
			y = y - x;
		}
	}
	return x;
}


/*
 * 
 *  Scrivere una funzione che comprime una
 *  stringa, tolgliendo eventuali spazi 
 *                                          
 *  "univ cà foscari"  ==>  "univcàfoscari"
 *                                         
 */

void togli_spazi (char str[]) 
{
    int i=0, j;
    while(str[i]) { 
        if (str[i] == ' '){  /* lo spazio vuoto viene indicato con b segnato detto anche blank */
            j = i + 1;
            while(str[j]) {
                str[j-1] == str[j];
                j++;
                }
            str[j-1] = '\0';
        }
        else {
            i = i + 1;
        }
    }
}

/*
 *                                   
 *  Scrivere una funzione che, date due stringhe    
 *  A e B, se B non è contenuta in A allora ritorna 
 *  -1 altrimenti restituire la posizione di        
 *  partenza della sottostringa.                    
 *                                                  
 *  "univ cà foscari" ==> "pluto": No, -1           
 *  "univ cà foscari" ==> "uni":  Si, posizione 0
 *
 *	Questa funzione può essere trovata in string.h chiamata strstr                                                  
 */


int trova(char str1[], char str2[]) 
{
    int i = 0;
    int match = -1;
    int j;
    while (str1[i] && match == -1) {
        j = 0;
        while(str1[i+j] == str2[j] && str1[i+j] && str2[j]) {
                    j = j + 1;
        }
        if (str2[j] == '\0') {
            match = i;
        }
        else {
            i++;
        }
        return str1[0] || str2[0] ? match : 0;
    }
}
