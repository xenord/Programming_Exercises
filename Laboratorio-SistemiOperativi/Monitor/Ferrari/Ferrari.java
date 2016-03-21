
public class Ferrari {

	static final int X=120;
	static final int Y=25;
	static final int OFFSET_X_AUTO = X/2 - 4;
	static final int QUANTE_AUTO=3;
	static final int OFFSET_Y_AUTO=7;
	static final int OFFSET_Y_NASTRO=3;
	static final int FINE_NASTRO_GOMMA= X/2 - X/6;
	static final int Y_NASTRO_GOMMA= Y/2;
	static final int DISTANZA_GOMMA = 4;

	char[][] screen = new char[X][Y];

	static final String[] car = {
		"O=[^]=O",
		"  / \\",
		" |( )|",
		"O=\\_/=O"
	};

	static final String[] carSruotata = {
		" =[^]= ",
		"  / \\",
		" |( )|",
		" =\\_/= "
	};

	 void mysleep(int i) {
		try {
			Thread.sleep(i);
		} catch(InterruptedException e) {
			System.out.println("Interrotto mentre dormivo? non dovrebbe succedere!");
			System.exit(1);
		}
	}

	 synchronized void printScreen() {
		int x,y;
		System.out.print("\033[H\033[2J");
		for (y=0;y<Y;y++) {
			for (x=0;x<X;x++) {
				System.out.print(screen[x][y]);
			}
			System.out.println();
		}
	}

	void  initScreen() {
		int x,y;
		for (y=0;y<Y;y++) {
			for (x=0;x<X;x++) {
				screen[x][y]=' ';
			}
		}

	}

	synchronized void stampaCar(String[] car, int y) {
		int i,j,w,yCar;

		for (i=0;i<7;i++) {
			for (j=0;j<Y;j++) {
				screen[i+OFFSET_X_AUTO][j]=' ';
			}
		}

		for (w=0;w<QUANTE_AUTO;w++) {
			yCar = y + w*OFFSET_Y_AUTO
	;
			for(i=0;i<car.length;i++) {
				if (yCar + i >= 0 && yCar + i < Y) {
					for (j=0;j<car[i].length();j++) {
						screen[OFFSET_X_AUTO+j][yCar+i] = car[i].charAt(j);
					}
				}
			}
		}
	}

	synchronized void stampaNastroGomme(int dx, int inizioNastro, int FINE_NASTRO_GOMMA, int lastGomma) {
		int i;

		for(i=inizioNastro;i!=FINE_NASTRO_GOMMA;i+=dx) {
			screen[i][Y_NASTRO_GOMMA-1] = '-';
			screen[i][Y_NASTRO_GOMMA+1] = '-';
		}
		screen[FINE_NASTRO_GOMMA][Y_NASTRO_GOMMA] = '|';
		screen[FINE_NASTRO_GOMMA][Y_NASTRO_GOMMA-1] = '+';
		screen[FINE_NASTRO_GOMMA][Y_NASTRO_GOMMA+1] = '+';
	}

	synchronized void checkGomme() {
		if( screen[56][3] != 'O' ||
			screen[56][6] != 'O' ||
			screen[62][3] != 'O' ||
			screen[62][6] != 'O' ||
			screen[56][10] != 'O' ||
			screen[56][13] != 'O' ||
			screen[62][10] != 'O' ||
			screen[62][13] != 'O' ||
			screen[56][17] != 'O' ||
			screen[56][20] != 'O' ||
			screen[62][17] != 'O' ||
			screen[62][20] != 'O' ) {
			System.out.println("Il nastro delle auto si sta muovendo prima che le gomme siano state montate!");
			System.exit(1);
		}
	}

	synchronized void stampaGomme(int dx, int inizioNastro, int FINE_NASTRO_GOMMA, int lastGomma) {
		int i;

		//for(i=inizioNastro;i<FINE_NASTRO_GOMMA;i++)
		screen[FINE_NASTRO_GOMMA-dx][Y_NASTRO_GOMMA] = ' ';

		for(i=lastGomma;i!=inizioNastro-dx;i-=dx) {
			if ((lastGomma-i)%DISTANZA_GOMMA ==0)
				screen[i][Y_NASTRO_GOMMA] = 'O';
			else
				screen[i][Y_NASTRO_GOMMA] = ' ';
		}
	}

	synchronized void checkNastroGomme(int FINE_NASTRO_GOMMA) {
		if (screen[FINE_NASTRO_GOMMA][Y_NASTRO_GOMMA] != ' ') {
			System.out.println("Hey una gomma sta cadendo dal nastro gomme! Il nastro dovrebbe fermarsi!" + screen[FINE_NASTRO_GOMMA][Y_NASTRO_GOMMA]);
			System.exit(1);
		}
	}

	synchronized void montaGomma(int x, int y, int dx) {
		if (screen[x+2*dx][y] != '=') {
			System.out.println("[gommista] Hey sto montando una gomma senza auto!");
			System.exit(1);
		}
		screen[x+dx][y] = 'O';
	}

	synchronized void prelevaGomma(int x, int y, int dx) {
		if (screen[x-2*dx][y] != 'O') {
			System.out.println("[gommista] Hey la gomma non c'è ancora!! Dovrei attendere!");
			System.exit(1);
		}
		screen[x-2*dx][y] = ' ';
	}

	synchronized void stampaGommista(char c, int oldx, int oldy, int newx, int newy) {
		if (screen[newx][newy] != ' ') {
			System.out.println("[gommista] hey sto andando a sbattere contro qualcun'altro!");
			System.exit(1);
		}
		screen[oldx][oldy] = ' ';
		screen[newx][newy] = c;
	}

	void portaMacchine(int ini,int end,String[] car) {
		int scroll, i;

		for(scroll=ini;scroll>=end;scroll--)
		{
			stampaCar(car, scroll);
			mysleep(200);
		}
	}

/*************************** INIZIO MAIN **********************************/
	public static void main(String[] args) throws InterruptedException{
		int i;

		Ferrari ferrari = new Ferrari();
		Mutex mutex = new Mutex(X,Y);
		Officina officina = new Officina(QUANTE_AUTO*4); // Monitor
		NastroAuto nastroAuto = new NastroAuto(ferrari,officina); // Thread
		NastroGomme nastroGommeLeft = new NastroGomme(ferrari,officina,1,FINE_NASTRO_GOMMA); //thread *
		NastroGomme nastroGommeRight = new NastroGomme(ferrari,officina,-1,X-FINE_NASTRO_GOMMA); // thread *
		Gommista[] gommista = new Gommista[QUANTE_AUTO*4]; // Thread
		Stampa stampa = new Stampa(ferrari);

		// crea i Thread gommisti con le coordinate corrette
		for (i=0;i<QUANTE_AUTO;i++) {
			gommista[i*4+1] = new Gommista(ferrari, mutex, officina, i*4+1,
				OFFSET_X_AUTO-1,
				OFFSET_Y_NASTRO + OFFSET_Y_AUTO*i,
				FINE_NASTRO_GOMMA+1,
				Y_NASTRO_GOMMA,1);
			gommista[i*4+3] = new Gommista(ferrari, mutex, officina, i*4+3,
				OFFSET_X_AUTO-1,
				OFFSET_Y_NASTRO+car.length-1+ OFFSET_Y_AUTO*i,
				FINE_NASTRO_GOMMA+1,
				Y_NASTRO_GOMMA,1);
			gommista[i*4] = new Gommista(ferrari, mutex, officina, i*4,
				OFFSET_X_AUTO+car[0].length(),
				OFFSET_Y_NASTRO + OFFSET_Y_AUTO*i,
				X-FINE_NASTRO_GOMMA-1,
				Y_NASTRO_GOMMA,-1);
			gommista[i*4+2] = new Gommista(ferrari, mutex,officina, i*4+2,
				OFFSET_X_AUTO+car[0].length(),
				OFFSET_Y_NASTRO+car.length-1+ OFFSET_Y_AUTO*i,
				X-FINE_NASTRO_GOMMA-1,
				Y_NASTRO_GOMMA,-1);
		}

		// inizializza lo schermo
		ferrari.initScreen();

		// fa partire i thread
		nastroAuto.start();
		nastroGommeLeft.start();
		nastroGommeRight.start();
		for (i=0;i<QUANTE_AUTO*4;i++)
			gommista[i].start();

		// fa partire i thread di stampa
		stampa.start();
	}
/* ****************************** FINE MAIN **************************************/
}

/********************************INIZI CLASSE MUTEX*******************************/
class Mutex {
	int X,Y; // dimensione dell'officina
	boolean posizione[][];

	Mutex(int X, int Y) {
		int i,j;

		this.X = X;
		this.Y = Y;

		posizione = new boolean[X][Y];

		for (i=0;i<X;i++) {
			for (j=0;j<Y;j++) {
				posizione[i][j] = true;
			}
		}
	}

	// il gommista attende che la posizione sia libera e la alloca
	public synchronized void occupaPosizione(int x, int y) throws InterruptedException {
		while (!posizione[x][y])
			wait();
		posizione[x][y] = false;
	}

	// il libera la posizione
	public synchronized void liberaPosizione(int x, int y) {
		posizione[x][y] = true;
		notifyAll();
	}
}
/*************************FINE CLASSE MUTEX **********************************/

/********************************INIZIO THREAD NASTROAUTO*******************************/
class NastroAuto extends Thread {
	Officina officina;
	Ferrari ferrari;

	NastroAuto(Ferrari ferrari, Officina officina) {
		this.officina = officina;
		this.ferrari = ferrari;
	}
	public void run() {
		while(true) {
			try {
				// Porta le macchine senza gomme
				ferrari.portaMacchine(ferrari.Y+ferrari.car.length,ferrari.OFFSET_Y_NASTRO,ferrari.carSruotata);

				// Attende il montaggio delle gomme
				officina.attendiMontaggioGomme();  /**** MONITOR ****/

				// verifica che le macchine abbiano veramente le gomme
				ferrari.checkGomme();
				// Porta via le macchine con le gomme
				ferrari.portaMacchine(ferrari.OFFSET_Y_NASTRO,-(ferrari.OFFSET_Y_NASTRO+ferrari.OFFSET_Y_AUTO
			*ferrari.QUANTE_AUTO), ferrari.car);
			} catch (InterruptedException e) {}
		}
	}
}

/********************************FINE THREAD NASTROAUTO*******************************/

/********************************INIZIO THREAD NASTROGOMME*******************************/
class NastroGomme extends Thread {
	int dx;
	int lastGomma;
	int fineNastro;
	int inizioNastro;
	Officina officina;
	Ferrari ferrari;

	NastroGomme(Ferrari ferrari, Officina officina, int dx, int fineNastro) {
		this.dx = dx;
		this.fineNastro = fineNastro;
		this.officina = officina;
		this.lastGomma = dx==1 ? 0 : ferrari.X-1;
		this.inizioNastro = this.lastGomma;
		this.ferrari = ferrari;
	}

	public void run() {
		// Stampa il nastro vuoto
		ferrari.stampaNastroGomme(dx,inizioNastro,fineNastro,lastGomma);

		while(true) {

			try {
				// stampa le gomme sul nastro
				ferrari.stampaGomme(dx,inizioNastro,fineNastro,lastGomma);

				ferrari.mysleep(200);

				// sposta le gomme sul nastro
				lastGomma += dx;

				// controlla se è in fondo al nastro
				if (lastGomma == fineNastro) {
					// se è in fondo attende che la gomma sia prelevata
					officina.gommaFineNastro(dx==1?1:0);  /**** MONITOR ****/

					// controlla che la gomma sia stata raccolta
					ferrari.checkNastroGomme(fineNastro-dx);

					// rimuove la gomma dal nastro
					lastGomma -= dx*ferrari.DISTANZA_GOMMA;
				}
			} catch (InterruptedException e) {}
		}
	}
}
/********************************FINE THREAD NASTROGOMME*******************************/

class Gommista extends Thread { /********************************INIZI THREAD GOMMISTA*******************************/
	int ix,iy,tx,ty,dx;
	int id;
	Officina officina;
	Mutex mutex;
	Ferrari ferrari;

	public Gommista(Ferrari ferrari, Mutex mutex, Officina officina, int id, int ix, int iy, int tx, int ty, int dx) {
		this.id = id;
		this.ix = ix;
		this.iy = iy;
		this.tx = tx;
		this.ty = ty;
		this.dx = dx;
		this.officina = officina;
		this.mutex = mutex;
		this.ferrari = ferrari;
		// System.out.println("" + id + " " + ix);
	}

	void moveto(char c, int ix, int iy, int tx, int ty) {
		int nx=ix,ny=iy,x=ix,y=iy;

		try {
			// si muove in orrizontale
			while(x != tx) {
				// calcola la nuova posizione
				nx = x + (tx<x?-1:1);

				// attende che la posizione sia libera e la alloca
				mutex.occupaPosizione(nx,ny);

				// il gommista si sposta
				ferrari.stampaGommista(c,x,y,nx,ny);

				// libera la posizione precedente
				mutex.liberaPosizione(x,y);

				// memorizza la nuova posizione
				x=nx;

				ferrari.mysleep(200);
			}

			// si muove in verticale
			while (y != ty) {
				// calcola la nuova posizione
				ny = y + (ty<y?-1:1);

				// attende che la posizione sia libera e la alloca
				mutex.occupaPosizione(nx,ny);

				// il gommista si sposta
				ferrari.stampaGommista(c,x,y,nx,ny);

				// libera la posizione precedente
				mutex.liberaPosizione(x,y);

				// memorizza la nuova posizione
				y=ny;

				ferrari.mysleep(200);
			}
		} catch (InterruptedException e) {}
	}
	public void run()
	{
		while(true) {
			try {
				// il gommista si sposta fino al nastro delle gomme
				moveto('x',ix,iy,tx,ty);

				// il gommista attende la gomma
				officina.attendiGomma(id);      /**** MONITOR ****/

				// il gommista rimuove la gomma dal nastro
				ferrari.prelevaGomma(tx,ty,dx);

				// il gommista notifica che ha prelevato la gomma
				officina.prelevataGomma(id);	/**** MONITOR ****/

				// il gommista si sposta fino all'auto per montare la gomma
				moveto('O',tx,ty,ix,iy);

				// il gommmista attende l'auto
				officina.attendiAuto(id);		/**** MONITOR ****/

				// il gommista monta la gomma
				ferrari.montaGomma(ix,iy,dx);

				// il gommista notifica il montaggio della gomma
				officina.gommaMontata(id);		/**** MONITOR ****/
			} catch (InterruptedException e) {}
		}
	}

}


class Stampa extends Thread {
	Ferrari ferrari;

	Stampa(Ferrari ferrari) {
		this.ferrari = ferrari;
	}

	public void run() {
		while(true) {
			ferrari.mysleep(50);
			ferrari.printScreen();
		}
	}
}
