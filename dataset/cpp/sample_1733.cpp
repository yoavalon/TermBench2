#include <iostream>
#include <vector>

class LedgerNode {
public:
    LedgerNode(int state) : state(state) {}

    void update_state(int new_state) {
        state = new_state;
    }

    int get_state() const {
        return state;
    }

private:
    int state;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(const std::vector<LedgerNode>& nodes) : nodes(nodes) {}

    void broadcast_state(int node_index, int new_state) {
        for (size_t i = 0; i < nodes.size(); ++i) {
            if (i != node_index) {
                nodes[i].update_state(new_state);
            }
        }
    }

    bool check_consensus() const {
        int first_node_state = nodes[0].get_state();
        for (const auto& node : nodes) {
            if (node.get_state() != first_node_state) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<LedgerNode> nodes;
};

int simulate_network(int nodes_count) {
    std::vector<LedgerNode> nodes;
    for (int i = 0; i < nodes_count; ++i) {
        nodes.emplace_back(i);
    }
    ConsensusMechanism consensus(nodes);
    while (true) {
        for (int i = 0; i < nodes_count; ++i) {
            int new_state = i + 1;
            consensus.broadcast_state(i, new_state);
            if (consensus.check_consensus()) {
                return consensus.nodes[0].get_state();
            }
        }
    }
}

int main() {
    int nodes_count = 5;
    int final_state = simulate_network(nodes_count);
    std::cout << final_state << std::endl;
    return 0;
}