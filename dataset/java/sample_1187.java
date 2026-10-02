public class sample_1187 {

    public static class ConsensusNode {
        int node_id;
        java.util.ArrayList<String> chain;
        java.util.ArrayList<ConsensusNode> neighbors;

        ConsensusNode(int node_id) {
            this.node_id = node_id;
            this.chain = new java.util.ArrayList<>();
            this.neighbors = new java.util.ArrayList<>();
        }

        void add_neighbor(ConsensusNode neighbor) {
            this.neighbors.add(neighbor);
        }

        void broadcast_transaction(String transaction) {
            this.chain.add(transaction);
            for (ConsensusNode neighbor : this.neighbors) {
                neighbor.receive_transaction(transaction);
            }
        }

        void receive_transaction(String transaction) {
            this.chain.add(transaction);
            this.propagate_transaction(transaction);
        }

        void propagate_transaction(String transaction) {
            for (ConsensusNode neighbor : this.neighbors) {
                neighbor.receive_transaction(transaction);
            }
        }
    }

    static java.util.ArrayList<ConsensusNode> create_network(int num_nodes) {
        java.util.ArrayList<ConsensusNode> nodes = new java.util.ArrayList<>();
        for (int i = 0; i < num_nodes; i++) {
            nodes.add(new ConsensusNode(i));
        }
        for (int i = 0; i < num_nodes; i++) {
            for (int j = i + 1; j < num_nodes; j++) {
                nodes.get(i).add_neighbor(nodes.get(j));
                nodes.get(j).add_neighbor(nodes.get(i));
            }
        }
        return nodes;
    }

    static void start_consensus(java.util.ArrayList<ConsensusNode> nodes) {
        int transaction_counter = 0;
        while (true) {
            String transaction = "Transaction-" + transaction_counter;
            nodes.get(0).broadcast_transaction(transaction);
            transaction_counter += 1;
        }
    }

    public static void main(String[] args) {
        java.util.ArrayList<ConsensusNode> nodes = create_network(5);
        start_consensus(nodes);
    }
}