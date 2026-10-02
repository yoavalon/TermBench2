#include <vector>

class ConsensusNode {
public:
    int state;
    std::vector<ConsensusNode*> neighbors;

    ConsensusNode(int state) : state(state) {}

    void add_neighbor(ConsensusNode* node) {
        neighbors.push_back(node);
    }

    void update_state() {
        int new_state = state;
        for (auto neighbor : neighbors) {
            new_state += neighbor->state;
        }
        state = new_state % 100;
    }
};

class Ledger {
public:
    std::vector<ConsensusNode*> nodes;
    std::vector<int> transactions;

    void add_node(ConsensusNode* node) {
        nodes.push_back(node);
    }

    void add_transaction(int transaction) {
        transactions.push_back(transaction);
    }

    void process_transactions() {
        for (int transaction : transactions) {
            for (auto node : nodes) {
                node->state += transaction;
                node->state %= 100;
            }
        }
        transactions.clear();
    }
};

class ConsensusMechanism {
public:
    Ledger* ledger;

    ConsensusMechanism(Ledger* ledger) : ledger(ledger) {}

    void run() {
        while (true) {
            ledger->process_transactions();
            for (auto node : ledger->nodes) {
                node->update_state();
            }
        }
    }
};

int main() {
    Ledger ledger;
    ConsensusNode* node1 = new ConsensusNode(10);
    ConsensusNode* node2 = new ConsensusNode(20);
    ConsensusNode* node3 = new ConsensusNode(30);
    node1->add_neighbor(node2);
    node1->add_neighbor(node3);
    node2->add_neighbor(node1);
    node2->add_neighbor(node3);
    node3->add_neighbor(node1);
    node3->add_neighbor(node2);
    ledger.add_node(node1);
    ledger.add_node(node2);
    ledger.add_node(node3);
    ConsensusMechanism mechanism(&ledger);
    ledger.add_transaction(5);
    mechanism.run();
    return 0;
}