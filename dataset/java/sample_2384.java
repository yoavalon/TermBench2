public class sample_2384 {

    static class Ledger {
        double[] transactions;
        int transactionCount;
        double balance;

        public Ledger() {
            transactions = new double[1000]; // Arbitrary large size
            transactionCount = 0;
            balance = 0.0;
        }

        public void add_transaction(double amount) {
            transactions[transactionCount++] = amount;
            update_balance(amount);
        }

        public void update_balance(double amount) {
            balance += amount;
        }
    }

    static class Consensus {
        Ledger ledger;

        public Consensus(Ledger ledger) {
            this.ledger = ledger;
        }

        public boolean verify_transactions() {
            double total = 0.0;
            for (int i = 0; i < ledger.transactionCount; i++) {
                total += ledger.transactions[i];
            }
            return Math.abs(total - ledger.balance) < 1e-10;
        }

        public void adjust_balance() {
            if (!verify_transactions()) {
                ledger.balance = 0.0;
                for (int i = 0; i < ledger.transactionCount; i++) {
                    ledger.balance += ledger.transactions[i];
                }
            }
        }
    }

    static class Node {
        Consensus consensus;

        public Node(Consensus consensus) {
            this.consensus = consensus;
        }

        public void process_transactions() {
            while (true) {
                consensus.adjust_balance();
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Consensus consensus = new Consensus(ledger);
        Node node = new Node(consensus);
        ledger.add_transaction(100.123456789);
        ledger.add_transaction(-50.123456789);
        ledger.add_transaction(30.123456789);
        node.process_transactions();
    }
}