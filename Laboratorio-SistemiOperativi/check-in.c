/*
int i;
		for(i=0; i<N, i++) {
			sem_init(&mutex[i], 0, 1);
			sem_init(&postazioni[i], 0, 0);
    	}
*/



#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <semaphore.h>
#include <stdint.h>
 
#define N 100   // Numero di viaggiatori
#define CIN 10  // Numero postazioni di check-int
 
/*********** variabili per il testing ************/
    int check_postazione[CIN];
    sem_t check_mutuo;
/*************************************************/
 
void * viaggiatore(void * i);
 
void die(char * s, int i) {
    printf("--> %s numero %i\n",s,i);
    exit(1);
    }
 
 
/*********** parte da consegnare ****************/
 
sem_t mutex[N];
sem_t postazioni[CIN];

 
// funzioni del main
inizializza() {
	int i;
	int j;
	for(i=0; i<N; i++) {
		sem_init(&mutex[i], 0, 0);
    	}
	for(j=0; j<CIN; j++) {
		sem_init(&postazioni[j], 0, 1);
    }
}
 
 
chiudi() {
	int i;
	int j;
	for(i=0; i<N; i++) {
		sem_destroy(&mutex[i]);
		}
	
	for(j=0; j<CIN; j++) {
		sem_destroy(&postazioni[j]);
    }
}
 
// funzioni del viaggiatore
int attendi_postazione() {
	int i;
	for(i=0; i<CIN; i++) {
		sem_wait(&postazioni[i]);
 		}
}
 
int libera_postazione(int j) {
	sem_post(&postazioni[j]);
 
}
/*********fine parte da consegnare **************/
 
 
void * viaggiatore(void * i) {
    int j;
    intptr_t id = (intptr_t)i;
 
    printf("[Viaggiatore %d] Entro in aeroporto\n", (int) id);
 
    j = attendi_postazione();
     
    /************** testing ***************/
        sem_wait(&check_mutuo);
        if (check_postazione[j]==1) 
            die("postazione gia' occupata",j);
        check_postazione[j]=1;
        sem_post(&check_mutuo);
    /**************************************/
     
    printf("[Viaggiatore %d] Sto usando lo sportello %d \n", (int) id, j);
     
    /*************** testing **************/
        sleep(1);
        check_postazione[j]=-1;
    /**************************************/
 
    libera_postazione(j);
         
     
    printf("[Viaggiatore %d] Vado al gate! \n", (int) id);
                     
}
 
crea_thread(pthread_t *th) {
    intptr_t i;
    int ret;
 
    for (i=0;i<N;i++)
        if(ret=pthread_create(&th[i],NULL,viaggiatore,(void *) i)) 
            die("errore create",ret);
}
 
attendi_thread(pthread_t *th) {
    intptr_t i;
    int ret;
 
    for (i=0;i<N;i++)
        if(ret=pthread_join(th[i], NULL))
             die("errore join",ret);
}
 
 
main() {
    pthread_t th[N];
    int i;
 
    sem_init(&check_mutuo,0,1);
         
    for (i=0; i<CIN; i++)
        check_postazione[i] = 0;
         
    // inizializza le strutture dati e i semafori
    inizializza();
 
    // crea i thread viaggiatori    
    crea_thread(th);
     
    printf("Creati %i viaggiatori \n", N);
 
    // attende la terminazione dei thread viaggiatori
    attendi_thread(th); 
     
    // distrugge i semafori 
    chiudi();
     
    /********************* testing *******************/
        for (i=0; i<CIN; i++) {
            if (check_postazione[i] == 0)
                die("postazione mai utilizzata",i);
        }
    /*************************************************/
}

