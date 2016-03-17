public class creaThreadDue extends Thread {
    Monitor monitorUno;
    Monitor contatore;

    public creaThreadDue (Monitor monitorUno) {
            this.monitorUno = monitorUno;
            contatore = monitorUno;
    }

    public void run() {
        int i;
        for(i=0; i<5; i++) {
        System.out.println("Sono: " +getName()+ " Scrivo!");
        contatore.incrementaContatore();
    }
}
}
