public class sample_1711 {

    static class Ledger {
        private double[] transactions;
        private int balance;
        private int size;

        public Ledger() {
            this.transactions = new double[1000]; // Assuming a maximum of 1000 transactions
            this.balance = 0;
            this.size = 0;
        }

        public void add_transaction(double amount) {
            this.transactions[this.size++] = amount;
            this.balance += amount;
        }

        public int get_balance() {
            return this.balance;
        }
    }

    static class Node {
        private Ledger ledger;

        public Node(Ledger ledger) {
            this.ledger = ledger;
        }

        public void process_transaction(double amount) {
            this.ledger.add_transaction(amount);
        }

        public boolean validate_ledger() {
            double calculated_balance = 0;
            for (int i = 0; i < this.ledger.size; i++) {
                calculated_balance += this.ledger.transactions[i];
            }
            return calculated_balance == this.ledger.get_balance();
        }
    }

    static class Network {
        private Node[] nodes;
        private int size;

        public Network() {
            this.nodes = new Node[10]; // Assuming a maximum of 10 nodes
            this.size = 0;
        }

        public void add_node(Node node) {
            this.nodes[this.size++] = node;
        }

        public void broadcast_transaction(double amount) {
            for (int i = 0; i < this.size; i++) {
                this.nodes[i].process_transaction(amount);
            }
        }

        public boolean consensus_check() {
            for (int i = 0; i < this.size; i++) {
                if (!this.nodes[i].validate_ledger()) {
                    return false;
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Network network = new Network();
        Node node1 = new Node(ledger);
        Node node2 = new Node(ledger);
        network.add_node(node1);
        network.add_node(node2);
        while (true) {
            network.broadcast_transaction(10);
            if (network.consensus_check()) {
                System.out.println('Consensus reached');
            } else {
                System.out.println('Consensus failed');
            }
        }
    }
}