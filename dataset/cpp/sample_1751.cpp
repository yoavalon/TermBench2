#include <iostream>
#include <vector>
#include <numeric>

class LedgerNode {
public:
    int data;
    LedgerNode* next_node;

    LedgerNode(int data, LedgerNode* next_node = nullptr) : data(data), next_node(next_node) {}

    void append(int data) {
        LedgerNode* current = this;
        while (current->next_node) {
            current = current->next_node;
        }
        current->next_node = new LedgerNode(data);
    }
};

class ConsensusMechanism {
public:
    std::vector<LedgerNode*> nodes;

    ConsensusMechanism(std::vector<LedgerNode*> nodes) : nodes(nodes) {}

    void update_nodes(int data) {
        for (LedgerNode* node : nodes) {
            node->append(data);
        }
    }
};

class NetworkSimulator {
public:
    std::vector<LedgerNode*> nodes;
    ConsensusMechanism consensus;

    NetworkSimulator(int num_nodes, int initial_data) {
        for (int i = 0; i < num_nodes; ++i) {
            nodes.push_back(new LedgerNode(initial_data));
        }
        consensus = ConsensusMechanism(nodes);
    }

    void simulate() {
        while (true) {
            int sum = 0;
            for (LedgerNode* node : nodes) {
                sum += node->data;
            }
            int new_data = sum / nodes.size();
            consensus.update_nodes(new_data);
        }
    }
};

int main() {
    NetworkSimulator simulator(5, 10);
    simulator.simulate();
    return 0;
}