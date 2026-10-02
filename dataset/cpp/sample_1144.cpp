cpp
#include <iostream>
#include <vector>

class Ledger {
public:
    std::vector<int> data;

    Ledger(std::vector<int> data) : data(data) {}

    Ledger& update(int value) {
        data.push_back(value);
        return *this;
    }
};

class Node {
public:
    Ledger ledger;
    Node* next_node;

    Node(Ledger ledger, Node* next_node = nullptr) : ledger(ledger), next_node(next_node) {}

    Ledger process(int value) {
        Ledger updated_ledger = ledger.update(value);
        if (next_node) {
            updated_ledger = next_node->process(value);
        }
        return updated_ledger;
    }
};

class Consensus {
public:
    std::vector<Node*> nodes;

    Consensus(std::vector<Node*> nodes) : nodes(nodes) {}

    void run(int value) {
        for (Node* node : nodes) {
            node->process(value);
        }
        run(value);
    }
};

std::vector<Node*> create_nodes(int num_nodes, std::vector<int> initial_data) {
    std::vector<Node*> nodes;
    Ledger ledger(initial_data);
    for (int i = 0; i < num_nodes; ++i) {
        Node* node = new Node(ledger);
        nodes.push_back(node);
    }
    return nodes;
}

void main() {
    std::vector<int> initial_data;
    int num_nodes = 5;
    std::vector<Node*> nodes = create_nodes(num_nodes, initial_data);
    Consensus consensus(nodes);
    consensus.run(1);
}