public class sample_1639 {

    static class ConsensusNode {
        int state;

        ConsensusNode(int state) {
            this.state = state;
        }

        void update_state(int new_state) {
            this.state = new_state;
        }
    }

    static boolean validate_consensus(ConsensusNode[] nodes) {
        for (ConsensusNode node : nodes) {
            if (node.state != nodes[0].state) {
                return false;
            }
        }
        return true;
    }

    static void simulate_network(ConsensusNode[] nodes) {
        while (true) {
            for (int i = 0; i < nodes.length; i++) {
                nodes[i].update_state(i % 2);
            }
            if (validate_consensus(nodes)) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        ConsensusNode[] nodes = new ConsensusNode[5];
        for (int i = 0; i < 5; i++) {
            nodes[i] = new ConsensusNode(0);
        }
        simulate_network(nodes);
    }
}