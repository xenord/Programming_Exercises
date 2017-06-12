#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define S1 "/tmp/pipe-s1"
#define S2 "/tmp/pipe-s2"
#define N 2 //Sequenza di numeri casuali, definito uguali anche in Sommatore_uno e Sommatore_due


/*
	Francesco Benetello 845626

	La soluzione che propongo è quella di creare due pipe S1 e S2 (Sommatore 1 e 2) che permettono la comunicazione tra i processi:
		generatore --S1--> sommatore 1
		generatore --S2--> sommatore 2
	
	L'idea è:
		distribuire i numeri casuali ai due processi mediante ciclo while(scorrendo Nx2 volte, N processi S1 e N processi S2) dove 
		ciclo (controllando che l'esito dell'apertura sia < 0, se >= 0 allora proseguo) finchè non riesco ad aprire la pipe in scrittura
		dove scrivo un numero casuale alle volta per ciclo, se "i" è pari allora assegno il numero a S1, altrimenti S2, per mantenere l'alternanza

*/



int fd[2];

int get_random_number() {
	int random_number = rand() % 100 + 1;
	return random_number;
}



int main(int argc, char const *argv[]) {
	int random_number;
	printf("SEQUENZA N: %d\n", N);
	for (int i = 0; i < (N*2); i++) {
		if ((i % 2) == 0) {	// seleziono i processi pari per assegnargli il numero casuale
			random_number = get_random_number();
			printf("[Processo - Generatore] --> [S1] Numero generato : %d\n", random_number);
			mkfifo(S1,0666); // Creo la pipe
			while ((fd[1] = open(S1, O_WRONLY)) < 0) {} // Ciclo a vuoto finchè non riesco ad aprire la pipe in scrittura
			write(fd[1], &random_number, 1); //Scrivo il numero casuale, 1 sta per un byte
			close(fd[1]);	// chiudo la pipe
			unlink(S1);		// distruggo la pipe
		}
		else {	// seleziono i processi dispari per assegnargli il numero casuale
			random_number = get_random_number();
			printf("[Processo - Generatore] --> [S2] Numero generato : %d\n", random_number);
			mkfifo(S2,0666);	//Creo la pipe
			while ((fd[1] = open(S2, O_WRONLY)) < 0) {} // Ciclo a vuoto finchè non riesco ad aprire la pipe in scrittura
			write(fd[1], &random_number, 1);
			close(fd[1]);	//chiudo la pipe
			unlink(S2);		//distruggo la pipe
		}
	}


	return 0;
}

