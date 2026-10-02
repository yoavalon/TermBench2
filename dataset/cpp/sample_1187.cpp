#include <iostream>
#include <vector>
#include <string>

class ConsensusNode {
public:
    ConsensusNode(int node_id) : node_id(node_id) {}

    void add_neighbor(ConsensusNode* neighbor) {
        neighbors.push_back(neighbor);
    }

    void broadcast_transaction(const std::string& transaction) {
        chain.push_back(transaction);
        for (ConsensusNode* neighbor : neighbors) {
            neighbor->receive_transaction(transaction);
        }
    }

    void receive_transaction(const std::string& transaction) {
        chain.push_back(transaction);
        propagate_transaction(transaction);
    }

    void propagate_transaction(const std::string& transaction) {
        for (ConsensusNode* neighbor : neighbors) {
            neighbor->receive_transaction(transaction);
        }
    }

private:
    int node_id;
    std::vector<std::string> chain;
    std::vector<ConsensusNode*> neighbors;
};

std::vector<ConsensusNode*> create_network(int num_nodes) {
    std::vector<ConsensusNode*> nodes;
    for (int i = 0; i < num_nodes; ++i) {
        nodes.push_back(new ConsensusNode(i));
    }
    for (int i = 0; i < num_nodes; ++i) {
        for (int j = i + 1; j < num_nodes; ++j) {
            nodes[i]->add_neighbor(nodes[j]);
            nodes[j]->add_neighbor(nodes[i]);
        }
    }
    return nodes;
}

void start_consensus(std::vector<ConsensusNode*>& nodes) {
    int transaction_counter = 0;
    while (true) {
        std::string transaction = "Transaction-" + std::to_string(transaction_counter);
        nodes[0]->broadcast_transaction(transaction);
        transaction_counter += 1;
    }
}

int main() {
    std::vector<ConsensusNode*> nodes = create_network(5);
    start_consensus(nodes);
    return 0;
}