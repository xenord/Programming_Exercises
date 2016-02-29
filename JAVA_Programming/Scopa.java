/* Applet Ballo della Scopa -- A. Raffaeta' & V. Gervasi */


import java.applet.*;
import java.awt.image.*;
import java.awt.*;

/**************************************************************************
   La classe astratta Ballerino implementa funzionalita' comuni a
   Dame e Cavalieri: attesa, animazione e movimento
***************************************************************************/

abstract class Ballerino extends Thread {
	protected int mioStato;			// stato corrente
	String mioNome;				// nome del Ballerino
	protected Image miaImmagine;		// immagine del Ballerino
	protected int casaX,casaY;		// posizione di riposo (parete)
	protected int curX,curY;		// posizione corrente
	protected int destX,destY;		// meta del movimento
	protected Sala miaSala;			// Sala in cui mi trovo
	protected Ballerino mioPartner=null;	// partner attuale
	protected boolean inMovimento;		// sono in movimento?

	void giraipollici() 			// attesa casuale 1-9 secondi
	{
		try {
			sleep((int)(1000+Math.random()*8000));
		} catch(InterruptedException e) {
			System.out.println("*** giraipollici() interruptus!");
		}
	}

	void disegna(Graphics g, ImageObserver a)
	{
		g.drawImage(miaImmagine,curX,curY,a);
		g.drawString(mioNome,curX+19,curY+58);
	}

	void passo(Graphics g,ImageObserver a,int vel) // passo dell'animazione
	{
		boolean moved=false;
		int i;

		for (i=0;i<vel;i++) {
			if (curX<destX) {curX++; moved=true; }
			if (curX>destX) {curX--; moved=true; }
			if (curY<destY) {curY++; moved=true; }
			if (curY>destY) {curY--; moved=true; }
		}
		disegna(g,a);
		if (inMovimento && (!moved)) {
			inMovimento=false;
			resume();
		}
	}

	void vai(int x, int y)			// imposta la destinazione
	{
		destX=x;	destY=y;
		inMovimento=true;
		suspend();
	}

	void vai(Ballerino b)			// raggiungi un Ballerino
	{
		int x=b.x();
		int y=b.y();
		vai(x+30,y);
	}

	void vaiCasa()				// vai verso la parete
	{
		vai(casaX,casaY);
	}

	abstract void vaiPista(Ballerino partner); // nel vortice delle danze!

	void vaiScopa()				// posizione di chi ha la scopa
	{
		vai(miaSala.scopaX(),miaSala.scopaY());
	}

	int x() { return curX; }
	int y() { return curY; }
	int casax() { return casaX; }
	int casay() { return casaY; }
	int stato() { return mioStato; }
	Ballerino partner() { return mioPartner; }
}


/* Definizione delle costanti che identificano i diversi stati del Cavaliere */

class StatoCav {
	static final int Parete=1;
	static final int Invito=2;
	static final int Ballo=3;
	static final int Scopa=4;
	static final int ScambioInCorso=5;
}


/**************************************************************************
   I Cavalieri possono attendere alla parete, invitare una dama, reggere la
   scopa o ricevere un ceffone (giusto premio per la loro sfacciataggine).
   Un cavaliere puo' anche trovarsi in uno stato intermedio (dovuto alla
   animazione) quando ha selezionato una vittima per lo scambio di scopa
   ed e' in attesa di raggiungerlo.
***************************************************************************/

class Cavaliere extends Ballerino {

	Cavaliere(String nome, boolean hoLaScopa, Sala sala, Image img,
			  int x, int y)
	{
		mioNome=nome;
		miaSala=sala;
		miaImmagine=img;
		mioPartner=null;
		inMovimento=false;
		casaX=destX=x;
		casaY=destY=y;
		curX=curY=-30;

		if (hoLaScopa)
			mioStato=StatoCav.Scopa;
		else
			mioStato=StatoCav.Parete;
	}

	public void run()
	{
		if (mioStato==StatoCav.Scopa)
			vaiScopa();		// ingresso nella Sala
		else
			vaiCasa();		// ingresso nella Sala
		automa();
	}

	void automa()
	{
		Cavaliere vittima;

		while (true) {
			switch (mioStato) {
				case StatoCav.Parete:
					giraipollici();
					mioPartner=miaSala.invito();
					vai(mioPartner);
					mioStato=StatoCav.Invito;
					break;
				case StatoCav.Invito:
					((Dama)mioPartner).invito(this);
					vaiPista(mioPartner);
					mioStato=StatoCav.Ballo;
					break;
				case StatoCav.Ballo:
					suspend();
					if (mioStato==StatoCav.Parete) {
						vaiCasa();
					} else {	/* stato=scopa */
						vaiScopa();
					}
					break;
				case StatoCav.Scopa:
					do {
						giraipollici();
						vittima=miaSala.scambio();
					} while (vittima==null);
					vai(vittima);
					mioPartner=vittima.partner();
					vittima.scambio();
					mioStato=StatoCav.ScambioInCorso;
					vaiPista(mioPartner);
					mioStato=StatoCav.Ballo;
					((Dama)mioPartner).scambio(this);
					break;
			}
		}
	}

	void scambio()	 	  // ho ricevuto la scopa
	{
		mioStato=StatoCav.Scopa;
		mioPartner=null;  // non ho piu' un partner
		resume();	  // dalla suspend() di StatoCav.Ballo
	}

	void schiaffo()		  // ho ricevuto uno schiaffo
	{
		mioStato=StatoCav.Parete;
		mioPartner=null;  // non ho piu' un partner
		resume();	  // dalla suspend() di StatoCav.Ballo
	}

	void vaiPista(Ballerino partner)
	{
		int x=(casaX+partner.casax())/2+10;
		int y=partner.casay();

		vai(x,y);
	}

	void disegna(Graphics g, ImageObserver a)
	{
		int ofX=43,ofY=15;

		super.disegna(g,a);
		if (mioStato==StatoCav.Scopa) {
		   g.drawLine(curX+ofX,curY+ofY,curX+ofX,curY+ofY+50);
		   g.drawLine(curX+ofX-2,curY+40+ofY,curX+ofX-4,curY+ofY+50);
		   g.drawLine(curX+ofX-4,curY+40+ofY,curX+ofX-7,curY+ofY+50);
		   g.drawLine(curX+ofX+2,curY+40+ofY,curX+ofX+4,curY+ofY+50);
		   g.drawLine(curX+ofX+4,curY+40+ofY,curX+ofX+7,curY+ofY+50);
		}
	}
}


/* Definizione delle costanti che identificano i diversi stati della Dama */

class StatoDama {
	static final int Parete=1;
	static final int Attesa_Cavaliere=2;
	static final int Ballo=3;
	static final int Attesa_Scambio=4;
	static final int TornoACasa=5;
}


/**************************************************************************
   Le Dame possono attendere alla parete o ballare, oppure trovarsi in uno
   stato intermedio (dovuto all'animazione): attesa che il cavaliere che le
   ha invitate arrivi ai loro piedi, attesa che si completi uno scambio di
   scopa o attesa di raggiungere la parete dopo uno schiaffo.
***************************************************************************/

class Dama extends Ballerino {

	Dama(String nome, Sala sala, Image img, int x, int y)
	{
		mioNome=nome;
		miaSala=sala;
		miaImmagine=img;
		inMovimento=false;
		casaX=destX=x;
		casaY=destY=y;
		curX=400; curY=-30;

		mioStato=StatoDama.Parete;
	}

	public void run()
	{
		vaiCasa();
		automa();
	}

	void automa()
	{
		while (true) {
			switch (mioStato) {
				case StatoDama.Parete:
					suspend();
					vaiPista(mioPartner);
					mioStato=StatoDama.Ballo;
					break;
				case StatoDama.Ballo:
					do {
						giraipollici();
					} while (miaSala.schiaffo(this));
					vaiCasa();
					mioStato=StatoDama.Parete;
					break;
			}
		}
	}

	void attendiInvito()		// che bello! sono stata invitata!
	{
		mioStato=StatoDama.Attesa_Cavaliere;
	}

	void invito(Cavaliere c)	// finalmente il cavaliere e' arrivato
	{
		mioPartner=c;
		resume();		// dalla suspend() di StatoDama.Parete
	}

	void attendiScambio()		// scambio in corso, niente schiaffi
	{
		mioStato=StatoDama.Attesa_Scambio;
	}

	void scambio(Cavaliere c)	// scambio concluso, torno a ballare
	{
		mioPartner=c;
		mioStato=StatoDama.Ballo;
	}

	void tornaACasa()		// screanzato! Torno alla parete
	{
		mioPartner=null;
		mioStato=StatoDama.TornoACasa;
	}

	void vaiPista(Ballerino partner)
	{
		int x=(casaX+partner.casax())/2-10;
		int y=casaY;

		vai(x,y);
	}
}


/**************************************************************************
  La Sala ha due compiti: gestisce le interazioni fra Dame e Cavalieri
  e implementa i metodi di Applet necessari al browser.
***************************************************************************/

public class Sala extends Applet {
	Cavaliere c[],inPista[];
	Dama d[],libera[];
	Walt disney;
	Cavaliere haLaScopa, avevaLaScopa;
	String brano=null;
	AudioClip orchestra=null;
	int N,scopax,scopay;
	int velocita=2;
	boolean primaEsecuzione=true;

	Image offscreen;
	Dimension offscreensize;
	Graphics offgraphics;

	public void init()
	{
		int i;
		Image icav,idam;

		initApplet();

		c=new Cavaliere[N+1];
		d=new Dama[N];
		inPista=new Cavaliere[N+1];
		libera=new Dama[N];

		icav=getImage(getDocumentBase(),"Cavaliere.gif");
		idam=getImage(getDocumentBase(),"Dama.gif");
		if (brano!=null)
			orchestra=getAudioClip(getDocumentBase(),brano);

		disney=new Walt(this);

		c[N]=new Cavaliere("C"+N,true,this,icav,330,10+N*50);
		haLaScopa=c[N];
		avevaLaScopa=null;
		for (i=0;i<N;i++) {
			c[i]=new Cavaliere("C"+i,false,this,icav,330,10+i*50);
			d[i]=new Dama("D"+i,this,idam,20,20+i*50);
		}
		scopax=175;
		scopay=40+N*50;
	}

	void initApplet()
	{
		String nCoppie = getParameter("N");
		String sVel = getParameter("velocita");

		brano = getParameter("brano");
		N=nCoppie!=null?Integer.valueOf(nCoppie).intValue():5;
		velocita=sVel!=null?Integer.valueOf(sVel).intValue():2;

		resize(400,110+N*50);
	}

	public void start()
	{
		int i;

		if (orchestra!=null) orchestra.loop();
		if (primaEsecuzione) {
			disney.start();
			for (i=0;i<N;i++) {
				d[i].start();
				c[i].start();
			}
			c[N].start();
			primaEsecuzione=false;
		} else
			disney.vai();
	}

	public void stop()
	{
		int i;

		disney.ferma();		// fermera' anche tutti gli altri
		if (orchestra!=null) orchestra.stop();
	}

	public void destroy()
	{
		int i;

		for (i=0; i<N; i++)
		{
			d[i].stop();
			c[i].stop();
		}
		c[N].stop();

		disney=null;
		for (i=0; i<N; i++)
		{
			d[i]=null;
			c[i]=null;
		}
		c[N]=null;
	}

	public void paint(Graphics g)
	{
		int i;

		for (i=0; i<N; i++)
			d[i].passo(g,this,velocita);
		for (i=0; i<N; i++)
			c[i].passo(g,this,velocita);
		c[N].passo(g,this,velocita);
	}

	public synchronized void update(Graphics g) {
		Dimension d = size();
		if ((offscreen == null) ||
		    (d.width != offscreensize.width) ||
		    (d.height != offscreensize.height)) {
			    offscreen = createImage(d.width, d.height);
			    offscreensize = d;
			    offgraphics = offscreen.getGraphics();
			    offgraphics.setFont(getFont());
		}

		offgraphics.setColor(getBackground());
		offgraphics.fillRect(0, 0, d.width, d.height);
		offgraphics.setColor(getForeground());
		paint(offgraphics);
		g.drawImage(offscreen, 0, 0, null);
	}

	public String getAppletInfo()
	{
		return "'Il Ballo della Scopa'" +
			"di Vincenzo Gervasi & Alessandra Raffaeta'";
	}

	public String[][] getParameterInfo() {
		String[][] info = {
			// Nome		Tipo		Descrizione
			{"N",		"int",		"numero di coppie"},
			{"brano",	"String",	"nome di un file .au"},
			{"velocita",	"int",		"passi per frame"}
		};
		return info;
	}

/***************************************************************************/

	synchronized Dama invito()		// chiamato dai Cavalieri
	{
		int i,nLibere=0,dado;

		System.out.println("invito()... ");

		for (i=0;i<N;i++)
			if (d[i].stato()==StatoDama.Parete)
				libera[nLibere++]=d[i];

		dado=(int)(Math.random()*nLibere);
		System.out.println("beccata "+dado+"/"+nLibere);
		libera[dado].attendiInvito();
		return libera[dado];
	}

	synchronized Cavaliere scambio()    // chiamato dai Cavalieri
	{
		int i,nInPista=0,dado;

		for (i=0;i<N;i++)
			if ( (c[i]!=avevaLaScopa) &&
			     (c[i].stato()==StatoCav.Ballo) &&
			     (c[i].partner().stato()==StatoDama.Ballo) )
				inPista[nInPista++]=c[i];
		if (nInPista==0)
			return null;
		dado=(int)(Math.random()*nInPista);
		((Dama)inPista[dado].partner()).attendiScambio();
		avevaLaScopa=haLaScopa;
		haLaScopa=inPista[dado];
		return inPista[dado];
	}

	synchronized boolean schiaffo(Dama d)	// chiamato dalle Dame
	{
		if ((d.stato()==StatoDama.Ballo) &&
		    (d.partner().stato()==StatoCav.Ballo)) {
			((Cavaliere)d.partner()).schiaffo();
			d.tornaACasa();
			return false;
		} else {
			return true;
		}
	}

	int scopaX() { return scopax;}
	int scopaY() { return scopay;}
}


class Walt extends Thread
{
	Sala sala;
	boolean fermo=false;

	Walt(Sala s)
	{
		sala=s;
	}

	public void run()
	{
		while (true) {
			if (fermo) suspend();
			sala.repaint();
			try {
				sleep(25);	// i.e., 40 fps
			} catch(InterruptedException e) {
				System.out.println("*** Walt interruptus!");
			}
		}
	}

	void ferma() { fermo=true;}
	void vai()   { fermo=false; resume(); }
}
