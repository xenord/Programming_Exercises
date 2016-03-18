/*
   Officina Ferrari. Corso di SO 2014/15 Ca' Foscari.

   Ci sono nGomme gommisti che montano gomme sulle auto. I gommisti devono attendere
   l'arrivo delle gomme su 2 nastri. Ogni gommista ha un id. Se l'id è pari attende
   le gomme dal nastro 0 (destro) se l'id è dispari dal nastro sinistro (1).
   i gommisti non si scontrano tra loro (questa sincronizzazione è già realizzata)

   Si devono realizzare le seguenti sincronizzazioni
   - i gommisti attendono la gomma sul nastro (attendiGomma)
   - i gommisti notificano l'avvenuto prelievo della gomma (prelevataGomma)
   - i nastri si fermano finché uno dei gommisti non preleva la gomma (gommaFineNastro)
   - i gommisti attendono le auto (attendiAuto)
   - i gommisti notificano l'avvenuto montaggio (gommaMontata)
   - le auto attendono il montaggio di tutte le gomme (attendiMontaggioGomme)


   le auto si comportano come segue
   while(true) {
     	 // Porta le macchine senza gomme

     	 // Attende il montaggio delle gomme
     	 officina.attendiMontaggioGomme();

     	 // Porta via le macchine con le gomme
    }

   i gommisti si comportano come segue:
	while(true) {
		// il gommista si sposta fino al nastro delle gomme

		// il gommista attende la gomma
		officina.attendiGomma(id);

		// il gommista rimuove la gomma dal nastro

		// il gommista notifica che ha prelevato la gomma
		officina.prelevataGomma(id);

		// il gommista si sposta fino all'auto per montare la gomma

		// il gommmista attende l'auto
		officina.attendiAuto(id);

		// il gommista notifica il montaggio della gomma
		officina.gommaMontata(id);
	}

 	i nastri delle gomme si comportano come segue:
	while(true) {

		// si muove

		// se è in fondo attende che la gomma sia prelevata
			officina.gommaFineNastro(n);
	}



 */

public class Officina {
	int nGomme; // numero gomme da montare
    boolean[] gomme = new boolean[nGomme];
    boolean[] fineNastro;
    boolean macchineArrivate;

	Officina(int nGomme) {
		this.nGomme = nGomme;
		inizializza();
	}

	void inizializza() {
        gomme = new boolean[nGomme];
        fineNastro = new boolean[2];
	}

	// il gommista id attende l'arrivo della gomma. I gommisti con id pari attendono dal
	// nastro di destra 0, quelli con id dispari dal nastro di sinistra 1
	public synchronized void attendiGomma(int id) throws InterruptedException {
        while (fineNastro[id%2] == false) {
            wait();
        }

	}

	// il gommista id notifica che ha prelevato una gomma dal proprio nastro
	public synchronized void prelevataGomma(int id) {
        fineNastro[id%2] = false;
        notifyAll();

	}

	// la gomma è arrivata a fine nastro n e attende di essere prelevata da un gommista
	// n vale 0 per il nastro di destra e 1 per il nastro di sinistra
	public synchronized void gommaFineNastro(int n) throws InterruptedException {
        while(fineNastro[n%2] == false) {
            wait();
        }

	}

	// il gommista id attende che l'auto arrivi
	public synchronized void attendiAuto(int id) throws InterruptedException {

	}

	// il gommista id ha montato la sua gomma
	public synchronized void gommaMontata(int id) {

	}

	// le auto sono in posizione e attendono il montaggio delle gomme
	public synchronized void attendiMontaggioGomme() throws InterruptedException {
            macchineArrivate = true;
            notify();
            int i=0;
            while (gomme[i] == false) {
                    wait();
                    i++;
            }

            macchineArrivate = false;
            for (i = 0; i<nGomme; i++) {
                gomme[i] = false;
            }

	}



}
