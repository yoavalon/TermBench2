public class sample_2190 {
    public static void ledger_consensus() {
        double x = 1.0;
        while (true) {
            x += 0.1;
            if (x >= 2.0) {
                x -= 2.0;
            }
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        ledger_consensus();
    }
}