public class sample_1770 {
    static class Ledger {
        private java.util.List<Integer> data;

        public Ledger(java.util.List<Integer> data) {
            this.data = data;
        }

        public void update_data(java.util.List<Integer> new_data) {
            this.data.addAll(new_data);
        }

        public java.util.List<Integer> get_data() {
            return this.data;
        }
    }

    static class ConsensusMechanic {
        private Ledger ledger;

        public ConsensusMechanic(Ledger ledger) {
            this.ledger = ledger;
        }

        public boolean validate_transaction(int transaction) {
            return this.ledger.get_data().contains(transaction);
        }

        public java.util.List<Integer> apply_consensus(java.util.List<Integer> transactions) {
            java.util.List<Integer> valid_transactions = new java.util.ArrayList<>();
            for (int t : transactions) {
                if (this.validate_transaction(t)) {
                    valid_transactions.add(t);
                }
            }
            this.ledger.update_data(valid_transactions);
            return valid_transactions;
        }
    }

    static class TransactionHandler {
        private ConsensusMechanic consensus_mechanic;

        public TransactionHandler(ConsensusMechanic consensus_mechanic) {
            this.consensus_mechanic = consensus_mechanic;
        }

        public java.util.List<Integer> process_transactions(java.util.List<Integer> transactions) {
            return this.consensus_mechanic.apply_consensus(transactions);
        }
    }

    public static void main(String[] args) {
        java.util.List<Integer> initial_data = java.util.Arrays.asList(1, 2, 3, 4, 5);
        Ledger ledger = new Ledger(initial_data);
        ConsensusMechanic consensus_mechanic = new ConsensusMechanic(ledger);
        TransactionHandler transaction_handler = new TransactionHandler(consensus_mechanic);
        while (true) {
            java.util.List<Integer> transactions = java.util.Arrays.asList(6, 7, 2, 8, 5);
            java.util.List<Integer> valid_transactions = transaction_handler.process_transactions(transactions);
            System.out.println("Valid transactions: " + valid_transactions);
        }
    }
}