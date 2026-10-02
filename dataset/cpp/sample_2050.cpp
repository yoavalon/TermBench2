#include <iostream>
#include <vector>
#include <string>

class ConsensusMechanism {
public:
    ConsensusMechanism(int nodes, double threshold) : nodes(nodes), threshold(threshold), votes(nodes, 0.0), state("pending") {}

    void record_vote(int node_index, double vote) {
        if (node_index < nodes) {
            votes[node_index] = vote;
            check_consensus();
        }
    }

    void check_consensus() {
        double total = 0.0;
        for (double vote : votes) {
            total += vote;
        }
        if (total >= threshold) {
            state = "consensus";
        }
    }

private:
    int nodes;
    double threshold;
    std::vector<double> votes;
    std::string state;
};

class Ledger {
public:
    Ledger(std::vector<double> data) : data(data) {}

    void update(int index, double value) {
        if (index < data.size()) {
            data[index] = value;
        }
    }

private:
    std::vector<double> data;
};

void main() {
    int nodes = 5;
    double threshold = 3.0;
    ConsensusMechanism mechanism(nodes, threshold);
    Ledger ledger(std::vector<double>(nodes, 0.0));
    for (int i = 0; i < nodes; ++i) {
        mechanism.record_vote(i, 1.0);
        ledger.update(i, 1.0);
    }
    if (mechanism.state == "consensus") {
        std::cout << "Consensus reached." << std::endl;
    } else {
        std::cout << "Consensus not reached." << std::endl;
    }
}

int main() {
    main();
    return 0;
}