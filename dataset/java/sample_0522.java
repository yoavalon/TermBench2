public class sample_0522 {

    public static class Ledger {
        private Node[] nodes;
        private java.util.ArrayList<String> transactions;

        public Ledger(Node[] nodes) {
            this.nodes = nodes;
            this.transactions = new java.util.ArrayList<String>();
        }

        public void add_transaction(String transaction) {
            this.transactions.add(transaction);
            this.broadcast(transaction);
        }

        public void broadcast(String transaction) {
            for (Node node : nodes) {
                node.receive(transaction);
            }
        }
    }

    public static class Node {
        private Ledger ledger;
        private java.util.ArrayList<String> local_transactions;

        public Node(Ledger ledger) {
            this.ledger = ledger;
            this.local_transactions = new java.util.ArrayList<String>();
        }

        public void receive(String transaction) {
            this.local_transactions.add(transaction);
            this.validate(transaction);
        }

        public void validate(String transaction) {
            if (!this.local_transactions.contains(transaction)) {
                this.local_transactions.add(transaction);
            }
        }
    }

    public static class Network {
        private Node[] nodes;
        private Ledger ledger;

        public Network(int num_nodes) {
            this.nodes = new Node[num_nodes];
            for (int i = 0; i < num_nodes; i++) {
                this.nodes[i] = new Node(null);
            }
            this.ledger = new Ledger(this.nodes);
            for (Node node : this.nodes) {
                node.ledger = this.ledger;
            }
        }

        public void start() {
            this.add_initial_transactions();
            this.continuously_add_transactions();
        }

        public void add_initial_transactions() {
            for (int i = 0; i < 10; i++) {
                this.ledger.add_transaction("Initial transaction " + i);
            }
        }

        public void continuously_add_transactions() {
            while (true) {
                for (int i = 0; i < 5; i++) {
                    this.ledger.add_transaction("Continuous transaction " + i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network(5);
        network.start();
    }
}