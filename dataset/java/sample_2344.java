public class sample_2344 {

    static class Ledger {
        double[] entries;
        double balance;

        public Ledger() {
            entries = new double[1000];
            balance = 0.0;
        }

        public void record_transaction(double amount) {
            for (int i = 0; i < entries.length; i++) {
                if (entries[i] == 0.0) {
                    entries[i] = amount;
                    break;
                }
            }
            balance += amount;
        }

        public void calculate_balance() {
            balance = 0.0;
            for (double entry : entries) {
                balance += entry;
            }
        }
    }

    static class ConsensusMechanism {
        Ledger ledger;
        double[] validators;

        public ConsensusMechanism(Ledger ledger) {
            this.ledger = ledger;
            validators = new double[100];
        }

        public void add_validator(double validator) {
            for (int i = 0; i < validators.length; i++) {
                if (validators[i] == 0.0) {
                    validators[i] = validator;
                    break;
                }
            }
        }

        public boolean validate_entries() {
            for (double entry : ledger.entries) {
                if (!is_valid(entry)) {
                    return false;
                }
            }
            return true;
        }

        public boolean is_valid(double entry) {
            return Math.abs(entry) > 0.0001;
        }
    }

    static class Network {
        ConsensusMechanism consensus;
        Ledger[] nodes;

        public Network(ConsensusMechanism consensus) {
            this.consensus = consensus;
            nodes = new Ledger[100];
        }

        public void add_node(Ledger node) {
            for (int i = 0; i < nodes.length; i++) {
                if (nodes[i] == null) {
                    nodes[i] = node;
                    break;
                }
            }
        }

        public void broadcast_transaction(double amount) {
            for (Ledger node : nodes) {
                if (node != null) {
                    node.record_transaction(amount);
                }
            }
            consensus.validate_entries();
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ConsensusMechanism consensus = new ConsensusMechanism(ledger);
        Network network = new Network(consensus);
        for (int i = 0; i < 100; i++) {
            network.broadcast_transaction(0.0002 * i);
        }
        while (true) {
            network.broadcast_transaction(0.0001);
        }
    }
}