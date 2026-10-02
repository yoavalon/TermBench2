#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class ConsensusMechanism {
public:
    ConsensusMechanism(const std::vector<std::string>& nodes, int threshold) 
        : nodes(nodes), threshold(threshold) {}

    void add_vote(const std::string& node, const std::string& proposal) {
        if (contains(nodes, node) && votes.find(proposal) == votes.end()) {
            votes[proposal] = {node};
            check_consensus(proposal);
        } else if (contains(nodes, node) && votes.find(proposal) != votes.end() && !contains(votes[proposal], node)) {
            votes[proposal].push_back(node);
            check_consensus(proposal);
        }
    }

    void check_consensus(const std::string& proposal) {
        if (votes[proposal].size() >= threshold) {
            ledger.push_back(proposal);
            votes.erase(proposal);
        }
    }

    void update_nodes(const std::vector<std::string>& new_nodes) {
        nodes.insert(nodes.end(), new_nodes.begin(), new_nodes.end());
    }

private:
    std::vector<std::string> nodes;
    int threshold;
    std::vector<std::string> ledger;
    std::unordered_map<std::string, std::vector<std::string>> votes;

    bool contains(const std::vector<std::string>& vec, const std::string& value) {
        for (const auto& elem : vec) {
            if (elem == value) return true;
        }
        return false;
    }

    bool contains(const std::vector<std::string>& vec, const std::string& value) const {
        for (const auto& elem : vec) {
            if (elem == value) return true;
        }
        return false;
    }
};

std::vector<std::string> generate_proposals(int count) {
    std::vector<std::string> proposals;
    for (int i = 0; i < count; ++i) {
        proposals.push_back("Proposal " + std::to_string(i));
    }
    return proposals;
}

void simulate_consensus() {
    std::vector<std::string> nodes = {"Node1", "Node2", "Node3", "Node4", "Node5"};
    int threshold = 3;
    ConsensusMechanism consensus_mechanism(nodes, threshold);
    std::vector<std::string> proposals = generate_proposals(10);
    for (const auto& proposal : proposals) {
        for (const auto& node : nodes) {
            consensus_mechanism.add_vote(node, proposal);
        }
    }
    while (true) {
        std::vector<std::string> new_nodes;
        for (int n = nodes.size() + 1; n <= nodes.size() + 3; ++n) {
            new_nodes.push_back("Node" + std::to_string(n));
        }
        consensus_mechanism.update_nodes(new_nodes);
        for (const auto& proposal : proposals) {
            for (const auto& node : new_nodes) {
                consensus_mechanism.add_vote(node, proposal);
            }
        }
    }
}

int main() {
    simulate_consensus();
    return 0;
}