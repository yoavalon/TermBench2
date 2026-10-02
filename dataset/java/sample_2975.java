public class sample_2975 {

    static class Ledger {
        private java.util.ArrayList<Integer> transactions;
        private int balance;

        public Ledger() {
            this.transactions = new java.util.ArrayList<>();
            this.balance = 0;
        }

        public void record_transaction(int amount) {
            this.transactions.add(amount);
            this.balance += amount;
        }

        public int get_balance() {
            return this.balance;
        }
    }

    static class ConsensusMechanism {
        private Ledger ledger;

        public ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
        }

        public boolean verify_transactions() {
            for (int transaction : this.ledger.transactions) {
                if (transaction < 0) {
                    throw new java.lang.RuntimeException("Invalid transaction");
                }
            }
            return true;
        }

        public void update_ledger() {
            while (true) {
                try {
                    this.verify_transactions();
                    this.ledger.balance = 0;
                    for (int transaction : this.ledger.transactions) {
                        this.ledger.balance += transaction;
                    }
                } catch (java.lang.RuntimeException e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }

    static class Simulation {
        private Ledger ledger;
        private ConsensusMechanism consensus;

        public Simulation(Ledger ledger, ConsensusMechanism consensus) {
            this.ledger = ledger;
            this.consensus = consensus;
        }

        public void run() {
            while (true) {
                int transaction = java.util.concurrent.ThreadLocalRandom.current().nextInt(-100, 101);
                this.ledger.record_transaction(transaction);
                this.consensus.update_ledger();
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusMechanism consensus = new ConsensusMechanism(ledger);
        Simulation simulation = new Simulation(ledger, consensus);
        simulation.run();
    }
}