public class sample_1144 {
    static class Ledger {
        private java.util.List<Integer> data;

        public Ledger(java.util.List<Integer> data) {
            this.data = data;
        }

        public Ledger update(int value) {
            this.data.add(value);
            return this;
        }
    }

    static class Node {
        private Ledger ledger;
        private Node next_node;

        public Node(Ledger ledger, Node next_node) {
            this.ledger = ledger;
            this.next_node = next_node;
        }

        public Ledger process(int value) {
            Ledger updated_ledger = this.ledger.update(value);
            if (this.next_node != null) {
                this.next_node.process(value);
            }
            return updated_ledger;
        }
    }

    static class Consensus {
        private java.util.List<Node> nodes;

        public Consensus(java.util.List<Node> nodes) {
            this.nodes = nodes;
        }

        public void run(int value) {
            for (Node node : this.nodes) {
                node.process(value);
            }
            this.run(value);
        }
    }

    public static java.util.List<Node> create_nodes(int num_nodes, java.util.List<Integer> initial_data) {
        java.util.List<Node> nodes = new java.util.ArrayList<>();
        Ledger ledger = new Ledger(initial_data);
        for (int i = 0; i < num_nodes; i++) {
            Node node = new Node(ledger, null);
            nodes.add(node);
        }
        return nodes;
    }

    public static void main(String[] args) {
        java.util.List<Integer> initial_data = new java.util.ArrayList<>();
        int num_nodes = 5;
        java.util.List<Node> nodes = create_nodes(num_nodes, initial_data);
        Consensus consensus = new Consensus(nodes);
        consensus.run(1);
    }
}