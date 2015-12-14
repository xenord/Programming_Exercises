#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /* Ho usato questa libreria per usare "fmodf" che mi permette di calcolare il modulo nei numeri float */

/* Authored: Francesco Benetello
 * Matricola: 845626
 * La mia idea è quella di usare il modulo per verificare se "snake" è nella stessa riga del cibo, se si faccio un tentativo
 * andando verso sinistra controllando se mi avvicino al cibo, se mi avvicino allora continuo ad andare verso sinistra finchè la distanza
 * è zero, altrimenti vado verso destra.
*/


#define writePIPE "/tmp/pipeSnakeIn"    /*pipe di ingresso per la scrittura che verra utilizzata per scrivere il mio risultato*/
#define readPIPE "/tmp/pipeSnakeOut"   /*pipe che viene utilizzata per la lettura della stringa in arrivo dal programma */
#define ROUND 20 /* Round che devo vincere */
#define WIDTH 8 /* lunghezza del buffer */
#define RIGHT '>' /*Istruzione per spostare a destra il nostro snake */
#define LEFT '<' /*Istruzione per spostare a sinistra il nostro snake */

void cancella_pipe() {
    unlink(writePIPE);        // Con questa istruzione si rimuove la pipe
    unlink(readPIPE);        // Con questa istruzione si rimuove la pipe
    exit(1);
}



int main(){

/*-------------------------------------------------------------------------VARIABILI----------------------------------------------------------------------------------*/

    int fw;  /*variabile che viene utilizzata per la gestione della SCRITTURA sulla pipe*/
    int fr; /*variabile che viene utilizzata per la gestione della LETTURA sulla pipe*/
    float buffer[8]; /* Quello che leggo dalla pipe */
    char istruzione; /* Variabile dove salvo l'istruzione da eseguire */
    int last_distance; /* Memorizzo la distanca precedente che ho letto */
    int i; /* Indice (usato nel for)*/

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------- CREAZIONE PIPE CON NOME ----------------------------------------------------------------------*/

    mkfifo(writePIPE, 0666); /*Si crea una pipe con nome e se esiste già allora non fa nulla*/
    mkfifo(readPIPE, 0666);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


/*------------------------In questa porzione di codice viene aperto un canale di communicazione tra i due processi utilizzando la open--------------------------------*/

    fr = open(readPIPE, O_RDONLY);    /*Apro la pipe solo in Lettura*/
    if(fr<0){ /*Controllo se la pipe e stata aperta con successo */
        perror("\nErrore apertura PIPE LETTURA");
        exit(1); /*Nel casi di un errore in apertura della pipe generato dalla open il programma termina*/
    }

    fw = open(writePIPE, O_WRONLY);    /*Apro la pipe solo in Scrittura*/
    if(fw<0){ /*Controllo se la pipe e stata aperta con successo */
        perror("\nErrore apertura PIPE SCRITTURA");
        exit(1); /*Nel casi di un errore in apertura della pipe generato dalla open il programma termina*/
    }

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*----------------------------------------------------------------- CALCOLO E PARSING --------------------------------------------------------------------------------*/

    for (i=0; i<ROUND; i++) {
        while(read(fr, &buffer, 8) != 0) { /* Fintanto che sono distante dal cibo resto nel ciclo.. */
            if (((*buffer) fmodf (2.0)) == 0.0) { /* Se questa condizione è vera significa che sono nella stessa riga del cibo */
                istruzione = LEFT; /*Faccio un tentativo andando verso sinistra controllando se mi avvicino */
                write(fw, &istruzione, 4); /*Mando l'istruzione '<' */
                last_distance = *buffer; /*Memorizzo la vecchia distanza per confrontarla con quella nuova per vedere si mi avvicino o meno*/
                if (read(fr, &buffer, 8) < *buffer) { /* tentativo andato a buon fine continuo ad andare a sinistra */
                        istruzione = LEFT;
                        write(fw, &istruzione, 4);
                }
                else {                              /* Tentativo fallito, vado verso destra */
                    istruzione = RIGHT;
                    write(fw, &istruzione, 4);
                }
            }
        }
    }q






/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------- CHIUSURA E CANCELLAZIONE DELLE PIPE IN LETTURA E SCRITTURA -------------------------------------------------------------*/
    close(fr);   /*chiudo la pipe in lettura*/
    close(fw);  /* chiudo la pipe in scrittura*/
    cancella_pipe(); /*viene utilizzata per la rimozione delle due pipe*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    return 0;
}
