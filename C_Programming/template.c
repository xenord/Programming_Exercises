#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * TESTO CONSEGNA
 *
*/


#define writePIPE "/tmp/pipeSnakeIn"    /*pipe di ingresso per la scrittura che verra utilizzata per scrivere il mio risultato*/
#define readPIPE "/tmp/pipeSnakeOut"   /*pipe che viene utilizzata per la lettura della stringa in arrivo dal programma */

void cancella_pipe() {
    unlink(writePIPE);        // Con questa istruzione si rimuove la pipe
    unlink(readPIPE);        // Con questa istruzione si rimuove la pipe
    exit(1);
}



int main(){

/*-------------------------------------------------------------------------VARIABILI----------------------------------------------------------------------------------*/

    int fw;  /*variabile che viene utilizzata per la gestione della SCRITTURA sulla pipe*/
    int fr; /*variabile che viene utilizzata per la gestione della LETTURA sulla pipe*/
    int buffer;
    char buffer[10];
    int intbuff[10];
    memset(intbuff,0,100);//setto a 0 tutto il buffer

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

    write(fw, 'S', 4);




/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------- CHIUSURA E CANCELLAZIONE DELLE PIPE IN LETTURA E SCRITTURA -------------------------------------------------------------*/
    close(fr);   /*chiudo la pipe in lettura*/
    close(fw);  /* chiudo la pipe in scrittura*/
    cancella_pipe(); /*viene utilizzata per la rimozione delle due pipe*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    return 0;
}
