import java.util.ArrayList;
import java.util.List;

public class sample_2020 {

    static class Ledger {
        List<Double> transactions;
        int precision;

        Ledger(int precision) {
            this.transactions = new ArrayList<>();
            this.precision = precision;
        }

        void add_transaction(double amount) {
            if (this.transactions.size() > this.precision) {
                this.transactions.remove(0);
            }
            this.transactions.add(amount);
        }

        double get_average_transaction() {
            if (this.transactions.isEmpty()) {
                return 0;
            }
            double sum = 0;
            for (double transaction : this.transactions) {
                sum += transaction;
            }
            return sum / this.transactions.size();
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;

        ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
        }

        void update_ledger(double new_amount) {
            this.ledger.add_transaction(new_amount);
        }

        boolean validate_transaction(double amount) {
            double avg_transaction = this.ledger.get_average_transaction();
            return Math.abs(amount - avg_transaction) < this.ledger.precision;
        }
    }

    static class Network {
        Ledger ledger;
        ConsensusMechanism consensus_mechanism;

        Network(int precision) {
            this.ledger = new Ledger(precision);
            this.consensus_mechanism = new ConsensusMechanism(this.ledger);
        }

        boolean process_transaction(double amount) {
            if (this.consensus_mechanism.validate_transaction(amount)) {
                this.consensus_mechanism.update_ledger(amount);
                return true;
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Network network = new Network(5);
        double[] amounts = {10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0};
        for (double amount : amounts) {
            if (!network.process_transaction(amount)) {
                System.out.println("Transaction " + amount + " rejected");
            } else {
                System.out.println("Transaction " + amount + " accepted");
            }
        }
    }
}