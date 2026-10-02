public class sample_1733 {
    static class LedgerNode {
        int state;

        LedgerNode(int state) {
            this.state = state;
        }

        void update_state(int new_state) {
            this.state = new_state;
        }

        int get_state() {
            return state;
        }
    }

    static class ConsensusMechanism {
        LedgerNode[] nodes;

        ConsensusMechanism(LedgerNode[] nodes) {
            this.nodes = nodes;
        }

        void broadcast_state(int node_index, int new_state) {
            for (int i = 0; i < nodes.length; i++) {
                if (i != node_index) {
                    nodes[i].update_state(new_state);
                }
            }
        }

        boolean check_consensus() {
            int first_node_state = nodes[0].get_state();
            for (LedgerNode node : nodes) {
                if (node.get_state() != first_node_state) {
                    return false;
                }
            }
            return true;
        }
    }

    static int simulate_network(int nodes_count) {
        LedgerNode[] nodes = new LedgerNode[nodes_count];
        for (int i = 0; i < nodes_count; i++) {
            nodes[i] = new LedgerNode(i);
        }
        ConsensusMechanism consensus = new ConsensusMechanism(nodes);
        while (true) {
            for (int i = 0; i < nodes_count; i++) {
                int new_state = i + 1;
                consensus.broadcast_state(i, new_state);
                if (consensus.check_consensus()) {
                    return consensus.nodes[0].get_state();
                }
            }
        }
    }

    public static void main(String[] args) {
        int nodes_count = 5;
        int final_state = simulate_network(nodes_count);
        System.out.println(final_state);
    }
}