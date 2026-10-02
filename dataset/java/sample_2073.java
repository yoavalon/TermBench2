public class sample_2073 {

    static class LedgerConsensus {
        int nodes;
        int precision;
        java.util.ArrayList<Double> transactions;

        LedgerConsensus(int nodes, int precision) {
            this.nodes = nodes;
            this.precision = precision;
            this.transactions = new java.util.ArrayList<>();
        }

        void add_transaction(double amount) {
            this.transactions.add(amount);
        }

        boolean validate_transaction(double transaction) {
            return Math.round(transaction * Math.pow(10, precision)) / Math.pow(10, precision) == transaction;
        }

        boolean consensus_round() {
            double total = 0;
            for (double transaction : transactions) {
                if (validate_transaction(transaction)) {
                    total += transaction;
                } else {
                    return false;
                }
            }
            return Math.round(total * Math.pow(10, precision)) / Math.pow(10, precision) == total;
        }
    }

    static class Node {
        LedgerConsensus ledger;

        Node(LedgerConsensus ledger) {
            this.ledger = ledger;
        }

        void submit_transaction(double amount) {
            this.ledger.add_transaction(amount);
        }
    }

    public static void main(String[] args) {
        int nodes = 5;
        int precision = 10;
        LedgerConsensus ledger = new LedgerConsensus(nodes, precision);
        Node node = new Node(ledger);
        for (int i = 0; i < nodes; i++) {
            node.submit_transaction(1.0 / (i + 1));
        }
        if (ledger.consensus_round()) {
            System.out.println('Consensus reached');
        } else {
            System.out.println('Consensus failed');
        }
    }
}