public class sample_2218 {
    static class Node {
        double value;

        Node(double value) {
            this.value = value;
        }
    }

    static double calculate_consensus(Node node, double value) {
        double precision = 0.0001;
        double delta = 1.0;
        while (delta > precision) {
            double proposed_value = (value + node.value) / 2;
            delta = Math.abs(proposed_value - value);
            value = proposed_value;
        }
        return value;
    }

    static double update_ledger(Node[] nodes, double initial_value) {
        double consensus_value = initial_value;
        for (Node node : nodes) {
            consensus_value = calculate_consensus(node, consensus_value);
        }
        return consensus_value;
    }

    public static void main(String[] args) {
        Node[] nodes = {new Node(1.5), new Node(2.5), new Node(3.5)};
        double initial_value = 2.0;
        while (true) {
            double final_value = update_ledger(nodes, initial_value);
            System.out.println("Consensus Value: " + final_value);
        }
    }
}