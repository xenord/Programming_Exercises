public class Monitor {
    private int counter = 0;

    public synchronized void incrementaContatore() {
        counter = counter + 1;
        notify();
    }

    public synchronized void leggiContatore() throws InterruptedException {
        System.out.println("Il contatore è: " + counter);
        wait();
    }

}
