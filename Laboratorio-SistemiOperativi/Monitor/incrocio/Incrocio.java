/*
 * Ci sono N_AUTO automobili che si approcciano a un incrocio regolato da semaforo, da 4 direzioni.
 * Le auto si comportano secondo il seguente schema:
 *
 ********
 *  finche' sulla strada:
 *
 *		Se all'incrocio:
 *			incr.semaforo(direzione); // direzione=true o false a seconda se orizzontale o verticale
 *
 *		incr.muovi(c,x,y,dx,dy); // la macchina si muove se la strada e' libera
 *		x+=dx; y+=dy;
 *
 *	    incr.libera(x,y); // esce dall'incrocio
 *********
 *
 * Progettare un monitor Incrocio che implementi i seguenti metodi:
 *
 * void muovi(char c, int x, int y, int dx, int dy)
 *   se la posizione x+dx,y+dy e' occupata attende. Altrimenti scrive c in tale posizione e libera
 *   la posizione attuale x,y invocando libera(x,y) (vedere sotto)
 *
 * void libera(int x, int y)
 *   libera la posizione x,y scrivendo uno spazio (viene invocata quando le auto escono dall'incrocio)
 *
 * void semaforo(Boolean d)
 *   e' il semaforo nell'incrocio. viene invocato con un booleano che indica la direzione
 *   (orizzontale o verticale). Il semaforo puo' essere verde in una direzione o rosso per entrambe
 *   se il semaforo e' rosso per la direzione d la macchina attende
 *
 * void cambiaSemaforo()
 *   viene invocata periodicamente e cambia lo stato del semaforo. Il semaforo deve 'ciclare' tra
 *   quattro stati: rosso per tutti, verde in una direzione, rosso per tutti, verde nell'altra direzione
 */
public class Incrocio {
	int DIM;
	char[][] strada;
	boolean[] semaforo = {true, false, false, false};

	/*
	 * Costruttore: genera la strada e la inizializza con spazi
	 * *** Non modificare ***
	 */
	public Incrocio(int DIM) {
		int i,j;
		this.DIM = DIM;
		this.strada = new char[DIM][DIM];
		for (i=0;i<DIM;i++)
			for (j=0;j<DIM;j++)
				strada[i][j] = ' ';
	}

	/*
	 * Restituisce il carattere alle coordinate x,y
	 * *** Non modificare ***
	 */
	public char strada(int x, int y) {
		return strada[x][y];
	}

	/*
	 * Aggingere codice per gestire la sincronizzazione
	 */


	public synchronized void muovi(char c, int x, int y, int dx, int dy) throws InterruptedException {
		/*
		 * Controlla che non ci sia un incidente, scrive c sulla strada e libera la
		 * posizione attuale. Non modificare
		 */
		 while (strada[x+dx][y+dy] != ' ') {
 			wait();
 		}
		
		if (strada[x+dx][y+dy] != ' ')
			strada[x+dx][y+dy] = '*'; // questo non dovrebbe accadere quando si sinconizzano!
		else
			strada[x+dx][y+dy] = c;
		libera(x,y);
		/****************************************************************************/
	}

	/*
	 * Aggiungere codice per gestire la sincronizzazione
	 */
	public synchronized void libera(int x, int y) {
		strada[x][y] = ' ';
		notifyAll();
	}

	public synchronized  void semaforo(Boolean d) throws InterruptedException {
		if ((semaforo[1] == true && d == true) || (semaforo[3] == true && d == true)) {
			notify();
		}
		else {
			wait();
		}

	}

	public synchronized void cambiaSemaforo() {
		if (semaforo[0] == true) {
			semaforo[0] = false;
			semaforo[1] = true;
		}
		else if (semaforo[1] == true) {
			semaforo[1] = false;
			semaforo[2] = true;
		}
		else if (semaforo[2]) {
			semaforo[2] = false;
			semaforo[3] = true;
		}
		else if (semaforo[3]){
			semaforo[3] = false;
			semaforo[0] = true;
		}

	}
}
