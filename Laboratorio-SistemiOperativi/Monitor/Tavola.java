public class Tavola {
    private final int N_BACCHETTE = 5;
    boolean bacchette[N_BACCHETTE];

    public Tavola {

    }

    public void initBacchette() {
        int i;
        for (i=0; i<N_BACCHETTE; i++) {
            bacchette[i] = true;
        }
    }

    public void raccogli (int i) throws InterruptedException {
        while (!bacchette[i] || !bacchette[(i+1)%5]) {
            filosofi[i].wait();
            bacchette[i] = false;
            bacchette[(i+1)%5] = false;
        }
    }

    public void deposita (int i) {
        bacchette[i] = true;
        bacchette[(i+1)%5] = true;
        filosofi[(i+4)%5].notify();
        filosofi[(i+1)%5].notify();
    }
}
