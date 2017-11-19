public class Monitor{
	
	boolean ricevuto;
	boolean spedito = true;
	boolean somma;
	int RandomNumber;

	public void setRandomNumber(int i) {
		this.RandomNumber = i;
	}

	public int getRandomNumber() {
		return RandomNumber;
	}


	public synchronized void attendiRicezione() throws InterruptedException {
		while(!ricevuto) {
			wait();
		}
		spedito = false;
	}

	public synchronized void notificaRicezione() {
		spedito = true;
		notify();	
	}

	public synchronized void attendiSpedizione() throws InterruptedException {
		while(!spedito) {
			wait();
		}
	}

	public synchronized void notificaSpedizione() {
		ricevuto = true;
		notify();
	}


	public synchronized void attendiContatore() throws InterruptedException {
		while (!somma) {
			wait();
		}
	}

	public synchronized void notificaContatore() {
		somma = true;
		notify();
	}

	
}