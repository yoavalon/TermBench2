public class sample_2381 {

    static class Ledger {
        private double[] records;
        private int index;
        private double balance;

        public Ledger() {
            this.records = new double[1000];
            this.index = 0;
            this.balance = 0.0;
        }

        public void recordTransaction(double amount) {
            this.records[this.index++] = amount;
            this.balance += amount;
        }

        public double getBalance() {
            return this.balance;
        }
    }

    static class ConsensusMechanism {
        private Ledger ledger;
        private double threshold;

        public ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
            this.threshold = 0.01;
        }

        public boolean verifyTransactions() {
            double total = 0.0;
            for (int i = 0; i < ledger.index; i++) {
                total += ledger.records[i];
            }
            if (Math.abs(total - ledger.balance) < threshold) {
                return true;
            }
            return false;
        }
    }

    static class Node {
        private Ledger ledger;
        private ConsensusMechanism consensus;

        public Node(Ledger ledger, ConsensusMechanism consensus) {
            this.ledger = ledger;
            this.consensus = consensus;
        }

        public boolean processTransactions(double[] transactions) {
            for (double transaction : transactions) {
                ledger.recordTransaction(transaction);
            }
            return consensus.verifyTransactions();
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusMechanism consensus = new ConsensusMechanism(ledger);
        Node node = new Node(ledger, consensus);
        double[] transactions = {0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01};
        while (true) {
            if (node.processTransactions(transactions)) {
                System.out.println("Consensus reached.");
            } else {
                System.out.println("Consensus not reached.");
            }
        }
    }
}