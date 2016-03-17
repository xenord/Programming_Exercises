

public class creaThread extends Thread {

    Monitor monitorUno;
    Monitor contatore;

    public creaThread(Monitor monitorUno) {
        this.monitorUno = monitorUno;
        this.contatore = monitorUno;
    }

    public void run() {
        int i;
        try {
            for(i=0; i<5; i++) {
                System.out.println("Sono " +getName()+ " LEGGO!");
                contatore.leggiContatore();
            }
        } catch (InterruptedException e) {
            System.out.println("Cacca");
        }
    }


    public static void main (String[] args) throws InterruptedException {
        Monitor monitorUno = new Monitor();
        /* Crea Thread da questa classe */
        creaThread threadUno = new creaThread(monitorUno);

        /* Crea Thread dalla classe ThreadDue */
        creaThreadDue threadDue = new creaThreadDue(monitorUno);

        //Parte esecuzione Thread
        threadUno.start();
        threadDue.start();

        //Termina esecuzione Thread
        threadUno.join();
        threadDue.join();

    }
}
