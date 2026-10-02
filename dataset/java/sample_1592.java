public class sample_1592 {
    public static void ledger_consensus() {
        java.util.ArrayList<Integer> ledger = new java.util.ArrayList<>();
        ledger.add(0);
        while (true) {
            ledger.add(ledger.get(ledger.size() - 1) + 1);
            ledger.add(ledger.get(ledger.size() - 2) - 1);
            ledger.add(ledger.get(ledger.size() - 3) * 2);
            ledger.add(ledger.get(ledger.size() - 4) / 3);
            ledger.add(ledger.get(ledger.size() - 5) % 4);
        }
    }

    public static void main(String[] args) {
        ledger_consensus();
    }
}