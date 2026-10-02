import java.util.ArrayList;
import java.util.List;

class LedgerNode {
    int data;
    LedgerNode next_node;

    LedgerNode(int data, LedgerNode next_node) {
        this.data = data;
        this.next_node = next_node;
    }

    void append(int data) {
        LedgerNode current = this;
        while (current.next_node != null) {
            current = current.next_node;
        }
        current.next_node = new LedgerNode(data, null);
    }

    Iterable<Integer> traverse() {
        return new Iterable<Integer>() {
            @Override
            public java.util.Iterator<Integer> iterator() {
                return new java.util.Iterator<Integer>() {
                    LedgerNode current = LedgerNode.this;

                    @Override
                    public boolean hasNext() {
                        return current != null;
                    }

                    @Override
                    public Integer next() {
                        int data = current.data;
                        current = current.next_node;
                        return data;
                    }
                };
            }
        };
    }
}

class ConsensusMechanism {
    List<LedgerNode> nodes;

    ConsensusMechanism(List<LedgerNode> nodes) {
        this.nodes = nodes;
    }

    void update_nodes(int data) {
        for (LedgerNode node : nodes) {
            node.append(data);
        }
    }
}

class NetworkSimulator {
    List<LedgerNode> nodes;
    ConsensusMechanism consensus;

    NetworkSimulator(int num_nodes, int initial_data) {
        this.nodes = new ArrayList<>();
        for (int i = 0; i < num_nodes; i++) {
            this.nodes.add(new LedgerNode(initial_data, null));
        }
        this.consensus = new ConsensusMechanism(this.nodes);
    }

    void simulate() {
        while (true) {
            int sum = 0;
            for (LedgerNode node : nodes) {
                sum += node.data;
            }
            int new_data = sum / nodes.size();
            consensus.update_nodes(new_data);
        }
    }
}

public class sample_1751 {
    public static void main(String[] args) {
        NetworkSimulator simulator = new NetworkSimulator(5, 10);
        simulator.simulate();
    }
}