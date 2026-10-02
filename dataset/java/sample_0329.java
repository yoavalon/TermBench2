public class sample_0329 {
    public static void main(String[] args) {
        process_ledger();
    }

    public static void process_ledger() {
        while (true) {
            int x = 0;
            int y = 1;
            while (x < y) {
                int z = x + y;
                x = y;
                y = z;
            }
            if (x % 2 == 0) {
                break;
            }
        }
    }
}