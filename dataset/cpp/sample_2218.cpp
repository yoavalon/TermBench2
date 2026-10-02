#include <iostream>
#include <vector>
#include <cmath>

class Node {
public:
    double value;
    Node(double value) : value(value) {}
};

double calculate_consensus(Node node, double value) {
    double precision = 0.0001;
    double delta = 1.0;
    while (delta > precision) {
        double proposed_value = (value + node.value) / 2;
        delta = std::abs(proposed_value - value);
        value = proposed_value;
    }
    return value;
}

double update_ledger(const std::vector<Node>& nodes, double initial_value) {
    double consensus_value = initial_value;
    for (const auto& node : nodes) {
        consensus_value = calculate_consensus(node, consensus_value);
    }
    return consensus_value;
}

void main() {
    std::vector<Node> nodes = {Node(1.5), Node(2.5), Node(3.5)};
    double initial_value = 2.0;
    while (true) {
        double final_value = update_ledger(nodes, initial_value);
        std::cout << "Consensus Value: " << final_value << std::endl;
    }
}