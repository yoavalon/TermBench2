public class sample_2319 {

    static class Ledger {
        int precision;
        double balance;
        java.util.ArrayList<Double> transactions;

        Ledger(int precision) {
            this.precision = precision;
            this.balance = 0.0;
            this.transactions = new java.util.ArrayList<>();
        }

        void record_transaction(double amount) {
            this.transactions.add(amount);
            this.balance += amount;
            this.balance = Math.round(this.balance * Math.pow(10, this.precision)) / Math.pow(10, this.precision);
        }

        double get_balance() {
            return this.balance;
        }

        int total_transactions() {
            return this.transactions.size();
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;
        int validator_count;

        ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
            this.validator_count = 0;
        }

        void add_validator() {
            this.validator_count += 1;
        }

        boolean validate_transaction(double amount) {
            if (this.validator_count > 0) {
                this.ledger.record_transaction(amount);
                return true;
            }
            return false;
        }

        int get_validator_count() {
            return this.validator_count;
        }
    }

    static class Network {
        Ledger ledger;
        ConsensusMechanism consensus;

        Network(int precision) {
            this.ledger = new Ledger(precision);
            this.consensus = new ConsensusMechanism(this.ledger);
        }

        void run() {
            this.consensus.add_validator();
            while (true) {
                double amount = 0.1;
                if (this.consensus.validate_transaction(amount)) {
                    System.out.println(this.ledger.get_balance());
                } else {
                    System.out.println('Validation failed');
                }
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network(10);
        network.run();
    }
}