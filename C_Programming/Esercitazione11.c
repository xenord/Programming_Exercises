/*
 ============================================================================
 Name        : Esercitazione11.c
 Author      : Francesco Benetello
 Version     : 0.0.1
 License     : GPL
 Copyright   : Your copyright notice
 Description : Esercitazione11 , Ansi-style, Risposta alla vita = 42 e piccolo esercizio di crittografia
 ============================================================================
 */
#include <stdio.h>
int vect[];

#define TRUE 1
#define FALSE 0
/*

void the_answer (int n) {
    do {
        printf("Qual'è la risposta della vita? ");
        scanf("%d", &n);
        
    } while (n != 42);
}

void print () {
    printf("Esatto!\n");
}


int main() {
    int n;
    the_answer(n);
    print();
    
} */


int is_prime(int n) {
    int i;
    if (n == 2) {
    }
    else {
        for (i=2; i<n; i++) {
            if ((n%i) == 0) {
                return 0;
            }
        }
    
    }
    return 1;
}

int* next_prime (int n, int m) {
    vect[m-n];
    int k, i=0;
    int* pi;
    pi = &i;
    while (n < m) {
        k = is_prime(n);
        if (k != 0){
        
            vect[i] = n;
            i++;
    
        }
        n++;
    }
    return &vect[0];
    
}




int main() {
    int i, m, n;
    printf("Insert a number(n): ");
    scanf("%d", &n);
    printf("Insert a number(m): ");
    scanf("%d", &m);
    int *vect = next_prime(n, m);

    int prova = is_prime(5);
    printf("%d\n\n", prova);
    for(i=0; i<m-n; i++) {
        printf("%d ", vect[i]);
    }
    return 0;
}










