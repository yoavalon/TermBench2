#include <iostream>
#include <vector>

class ConsensusNode {
public:
    int state;

    ConsensusNode(int state) : state(state) {}

    void update_state(int new_state) {
        state = new_state;
    }
};

bool validate_consensus(const std::vector<ConsensusNode>& nodes) {
    for (const auto& node : nodes) {
        if (node.state != nodes[0].state) {
            return false;
        }
    }
    return true;
}

void simulate_network(std::vector<ConsensusNode>& nodes) {
    while (true) {
        for (size_t i = 0; i < nodes.size(); ++i) {
            nodes[i].update_state(i % 2);
        }
        if (validate_consensus(nodes)) {
            break;
        }
    }
}

int main() {
    std::vector<ConsensusNode> nodes(5, ConsensusNode(0));
    simulate_network(nodes);
    return 0;
}