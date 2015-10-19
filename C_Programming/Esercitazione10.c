/*
 ============================================================================
 Name        : Esercitazione10.c
 Author      : Francesco Benetello
 Version     : 0.0.1
 License     : GPL
 Copyright   : Your copyright notice
 Description : Esercitazione10 , Ansi-style, Perfect number example: 28 = 1 + 2 + 4 + 7 + 14
 ============================================================================
 */


#include <stdio.h>

int n=0, i, j;

int main() {
    printf("Inserisci un numero:\n");
    scanf("%d", &n);
    for (i=1; i<n; i++) {
        if ((n % i) == 0) {
        j = j + i;
    }
}
    
    if (j == n) {
        printf("E' un numero perfetto!\n");
    }
    else {
        printf("Non è un numero perfetto!\n");
    }
    return 0;
}
