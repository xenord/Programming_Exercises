import java.util.Random;

public class Generatore extends Thread {

	static final int MAX = 100;
	static final int MIN = 1;
	static final int N = 5;
	Sommatori s1;
	Sommatori s2;
	Monitor m_s1;
	Monitor m_s2;
	int somma = 0;

	public Generatore(Monitor m_s1 , Monitor m_s2) {
		this.m_s1 = m_s1;
		this.m_s2 = m_s2;
	}


	public void setSommatoriS1(Sommatori s1) {
		this.s1 = s1;
	}

	public void setSommatoriS2(Sommatori s2) {
		this.s2 = s2;
	}

	public static int randInt(int min, int max) {
    	Random rand = new Random();
	    int randomNum = rand.nextInt((max - min) + 1) + min;

	    return randomNum;
	}

	public void run() {
		int randomNumber;

		//System.out.println("Numero generato: " + randomNumber);
		try {
			for (int i=0; i<N; i++) {
				m_s1.attendiSpedizione();
				randomNumber = randInt(MIN, MAX);
				m_s1.setRandomNumber(randomNumber);
				m_s1.notificaSpedizione();

				m_s2.attendiSpedizione();
				randomNumber = randInt(MIN, MAX);
				m_s2.setRandomNumber(randomNumber);
				m_s2.notificaSpedizione();
			}

			m_s1.attendiContatore();
			somma = s1.getContatore() + somma;
			System.out.println("[Generatore] Ho ricevuto da Sommatore UNO il contaore: " + s1.getContatore());

			m_s2.attendiContatore();
			somma = s2.getContatore() + somma;
			System.out.println("[Generatore] Ho ricevuto da Sommatore DUE il contaore: " + s2.getContatore());
			System.out.println("La somma TOTALE dei due contatori è: " + somma);



		} catch (InterruptedException e) {
			System.out.println("Questo non dovrebbe succedere");
		}




	}
	

	public static void main(String[] args) throws InterruptedException {
		Monitor m_s1 = new Monitor();
		Monitor m_s2 = new Monitor();
		Generatore g = new Generatore(m_s1, m_s2);

		Sommatori s1 = new Sommatori("s1", g, m_s1);
		Sommatori s2 = new Sommatori("s2", g, m_s2);

		g.setSommatoriS1(s1);
		g.setSommatoriS2(s2);

		g.start();
		s1.start();
		s2.start();

		g.join();
		s1.join();
		s2.join();
		
	}
}


class Sommatori extends Thread {
	private Generatore g;
	private int contatore = 0;
	static final int N = 5;
	private int ricevuto = 0;
	private String identificativo_thread;
	private Monitor m;

	public Sommatori(String identificativo_thread, Generatore g, Monitor m) {
		this.identificativo_thread = identificativo_thread;
		this.g = g;
		this.m = m;
	}

	public int getContatore() {
		return contatore;
	}

	public void setContatore(int i) {
		this.ricevuto = i;
		this.contatore = this.contatore + i;
	}

	public void run() {
		try {
			for (int i=0; i<g.N; i++) {
				m.attendiRicezione();
				ricevuto = m.getRandomNumber();
				System.out.println("["+identificativo_thread+"] Numero ricevuto: " + ricevuto);
				this.setContatore(ricevuto);
				m.notificaRicezione();
				//fermati attendi nunero
				//setContatore();
				//Notifica il thread generatore che ha finito
			}

			m.notificaContatore();
		} catch (InterruptedException e) {
			System.out.println("Questo non dovrebbe succedere");
		}

	}
}