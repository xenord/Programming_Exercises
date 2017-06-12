#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


#define S2 "/tmp/pipe-s2"
#define N 2 //Sequenza di numeri casuali, definito uguali anche in Sommatore_uno e Sommatore_due

/*
	Francesco Benetello 845626


*/

int buffer;
int contatore = 0; // inizializzo contatore
int fd;

int main(int argc, char const *argv[]) {

	int i = 0;
	while (i<N) {
		close(fd);
		/* Blocco finchè non viene scritto */
		memset(&buffer, 0, 1);
		while ((fd = open(S2, O_RDONLY)) < 0) {} // Ciclo a vuoto finchè non riesco ad aprire la pipe in lettura
		read(fd, &buffer, sizeof(buffer));
		printf("[S2] Ho ricevuto: %d\n", buffer);
		contatore = contatore + buffer; // incremento il contatore 
		close(fd);
		i++;
	}

	printf("[Sommatore - 2] Contatore: %d\n", contatore);

	return 0;
}