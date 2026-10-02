#include <iostream>
#include <vector>
#include <string>

class LedgerNode {
public:
    int id;
    std::vector<LedgerNode*> peers;
    std::string status;

    LedgerNode(int identifier, std::vector<LedgerNode*> peers) : id(identifier), peers(peers), status("active") {}

    void broadcast(const std::string& message) {
        for (LedgerNode* peer : peers) {
            peer->receive(message);
        }
    }

    void receive(const std::string& message) {
        std::cout << "Node " << id << " received: " << message << std::endl;
    }

    void update_status() {
        status = (status == "active") ? "inactive" : "active";
    }
};

class Network {
public:
    std::vector<LedgerNode*> nodes;

    Network(std::vector<LedgerNode*> nodes) : nodes(nodes) {}

    void initiate_consensus() {
        std::string initial_message = "consensus_initiated";
        for (LedgerNode* node : nodes) {
            node->broadcast(initial_message);
        }
    }

    void cycle_statuses() {
        for (LedgerNode* node : nodes) {
            node->update_status();
        }
    }
};

int main() {
    std::vector<LedgerNode*> nodes;
    for (int i = 0; i < 10; ++i) {
        nodes.push_back(new LedgerNode(i, {}));
    }
    Network network(nodes);
    for (LedgerNode* node : nodes) {
        node->peers = nodes;
    }
    while (true) {
        network.initiate_consensus();
        network.cycle_statuses();
    }
    return 0;
}