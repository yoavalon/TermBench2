public class sample_2063 {

    static class Ledger {
        double[] data;
        double balance;

        Ledger(double[] data) {
            this.data = data;
            this.balance = 0;
        }

        void update_balance(double amount) {
            this.balance += amount;
        }

        double get_balance() {
            return this.balance;
        }
    }

    static class Consensus {
        Ledger ledger;
        double threshold;

        Consensus(Ledger ledger) {
            this.ledger = ledger;
            this.threshold = 0.0001;
        }

        boolean verify_transaction(double amount) {
            if (Math.abs(amount) > threshold) {
                return true;
            }
            return false;
        }

        void process_transactions(double[] transactions) {
            for (double transaction : transactions) {
                if (verify_transaction(transaction)) {
                    ledger.update_balance(transaction);
                }
            }
        }
    }

    static class Analysis {
        Ledger ledger;

        Analysis(Ledger ledger) {
            this.ledger = ledger;
        }

        double calculate_precision_error() {
            double balance = ledger.get_balance();
            double error = balance - Math.floor(balance);
            return error;
        }
    }

    public static void main(String[] args) {
        double[] data = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
        Ledger ledger = new Ledger(data);
        Consensus consensus = new Consensus(ledger);
        Analysis analysis = new Analysis(ledger);
        double[] transactions = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
        consensus.process_transactions(transactions);
        double error = analysis.calculate_precision_error();
        System.out.println("Floating point precision error: " + error);
    }
}