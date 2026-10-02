public class sample_0027 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        java.util.ArrayList<Integer> ledger = new java.util.ArrayList<>();
        int validators = 5;
        double consensus_threshold = validators * 2 / 3;
        int block = 0;
        int transactions = 10;
        while (block < transactions) {
            ledger.add(block);
            if (ledger.size() >= consensus_threshold) {
                block += 1;
                ledger.clear();
            }
        }
    }
}