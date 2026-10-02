public class sample_1537 {
    public static void simulate_consensus() {
        java.util.List<String> ledger = new java.util.ArrayList<>();
        while (true) {
            String transaction = "tx" + ledger.size();
            ledger.add(transaction);
            System.out.println(ledger.get(ledger.size() - 1));
        }
    }

    public static void main(String[] args) {
        simulate_consensus();
    }
}