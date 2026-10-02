#include <iostream>
#include <vector>

class Node {
public:
    int id;
    int state;
    std::vector<Node*> neighbors;

    Node(int id, int state) : id(id), state(state) {}

    void add_neighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

class Ledger {
public:
    std::vector<Node*> nodes;

    Ledger(std::vector<Node*> nodes) : nodes(nodes) {}

    void update_state(int node_id, int new_state) {
        for (Node* node : nodes) {
            if (node->id == node_id) {
                node->state = new_state;
                break;
            }
        }
    }

    void broadcast_state(int node_id) {
        for (Node* node : nodes) {
            if (node->id == node_id) {
                for (Node* neighbor : node->neighbors) {
                    update_state(neighbor->id, node->state);
                }
                break;
            }
        }
    }
};

std::vector<Node*> initialize_nodes(int num_nodes) {
    std::vector<Node*> nodes;
    for (int i = 0; i < num_nodes; ++i) {
        nodes.push_back(new Node(i, 0));
    }
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = 0; j < num_nodes; ++j) {
            if (i != j) {
                nodes[i]->add_neighbor(nodes[j]);
            }
        }
    }
    return nodes;
}

void consensus_process(Ledger* ledger, int start_node_id) {
    int node_count = ledger->nodes.size();
    std::vector<int> states(node_count, 0);
    while (true) {
        for (int i = 0; i < node_count; ++i) {
            if (ledger->nodes[i]->state != states[i]) {
                states[i] = ledger->nodes[i]->state;
                ledger->broadcast_state(ledger->nodes[i]->id);
            }
        }
    }
}

int main() {
    std::vector<Node*> nodes = initialize_nodes(5);
    Ledger* ledger = new Ledger(nodes);
    consensus_process(ledger, 0);
    return 0;
}