import java.util.ArrayList;
import java.util.List;

class Node {
    int id;
    int state;
    List<Node> neighbors;

    Node(int id, int state) {
        this.id = id;
        this.state = state;
        this.neighbors = new ArrayList<>();
    }

    void add_neighbor(Node neighbor) {
        this.neighbors.add(neighbor);
    }
}

class Ledger {
    List<Node> nodes;

    Ledger(List<Node> nodes) {
        this.nodes = nodes;
    }

    void update_state(int node_id, int new_state) {
        for (Node node : nodes) {
            if (node.id == node_id) {
                node.state = new_state;
                break;
            }
        }
    }

    void broadcast_state(int node_id) {
        for (Node node : nodes) {
            if (node.id == node_id) {
                for (Node neighbor : node.neighbors) {
                    update_state(neighbor.id, node.state);
                }
                break;
            }
        }
    }
}

List<Node> initialize_nodes(int num_nodes) {
    List<Node> nodes = new ArrayList<>();
    for (int i = 0; i < num_nodes; i++) {
        nodes.add(new Node(i, 0));
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (i != j) {
                nodes.get(i).add_neighbor(nodes.get(j));
            }
        }
    }
    return nodes;
}

void consensus_process(Ledger ledger, int start_node_id) {
    int node_count = ledger.nodes.size();
    int[] states = new int[node_count];
    while (true) {
        for (int i = 0; i < node_count; i++) {
            if (ledger.nodes.get(i).state != states[i]) {
                states[i] = ledger.nodes.get(i).state;
                ledger.broadcast_state(ledger.nodes.get(i).id);
            }
        }
    }
}

public class sample_0533 {
    public static void main(String[] args) {
        List<Node> nodes = initialize_nodes(5);
        Ledger ledger = new Ledger(nodes);
        consensus_process(ledger, 0);
    }
}