#include <iostream>
#include <vector>
#include <random>
#include <numeric>

class ConsensusNode {
public:
    int id;
    double value;
    std::vector<ConsensusNode*> neighbors;

    ConsensusNode(int id) : id(id), value(static_cast <double> (rand()) / RAND_MAX) {}

    void connect(ConsensusNode* node) {
        neighbors.push_back(node);
    }

    void update_value() {
        double total = 0;
        for (auto neighbor : neighbors) {
            total += neighbor->value;
        }
        value = total / neighbors.size();
    }
};

class LedgerSystem {
public:
    std::vector<ConsensusNode*> nodes;

    LedgerSystem(std::vector<ConsensusNode*> nodes) : nodes(nodes) {}

    void perform_round() {
        for (auto node : nodes) {
            node->update_value();
        }
    }
};

class ConsensusMechanics {
public:
    LedgerSystem* system;

    ConsensusMechanics(LedgerSystem* system) : system(system) {}

    void run() {
        while (true) {
            system->perform_round();
        }
    }
};

int main() {
    std::vector<ConsensusNode*> nodes;
    for (int i = 0; i < 10; ++i) {
        nodes.push_back(new ConsensusNode(i));
    }
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            nodes[i]->connect(nodes[(i + j + 1) % nodes.size()]);
        }
    }
    LedgerSystem* system = new LedgerSystem(nodes);
    ConsensusMechanics* mechanics = new ConsensusMechanics(system);
    mechanics->run();
    return 0;
}