#include <iostream>
#include <vector>
#include <string>

class Ledger {
public:
    Ledger(const std::vector<class Node*>& nodes) : nodes(nodes) {}

    void add_transaction(const std::string& transaction) {
        transactions.push_back(transaction);
        broadcast(transaction);
    }

    void broadcast(const std::string& transaction) {
        for (auto* node : nodes) {
            node->receive(transaction);
        }
    }

private:
    std::vector<class Node*> nodes;
    std::vector<std::string> transactions;
};

class Node {
public:
    Node(class Ledger* ledger) : ledger(ledger) {}

    void receive(const std::string& transaction) {
        local_transactions.push_back(transaction);
        validate(transaction);
    }

    void validate(const std::string& transaction) {
        if (std::find(local_transactions.begin(), local_transactions.end(), transaction) == local_transactions.end()) {
            local_transactions.push_back(transaction);
        }
    }

private:
    class Ledger* ledger;
    std::vector<std::string> local_transactions;
};

class Network {
public:
    Network(int num_nodes) {
        for (int i = 0; i < num_nodes; ++i) {
            nodes.push_back(new Node(this));
        }
        ledger = new Ledger(nodes);
    }

    ~Network() {
        for (auto* node : nodes) {
            delete node;
        }
        delete ledger;
    }

    void start() {
        add_initial_transactions();
        continuously_add_transactions();
    }

private:
    void add_initial_transactions() {
        for (int i = 0; i < 10; ++i) {
            ledger->add_transaction("Initial transaction " + std::to_string(i));
        }
    }

    void continuously_add_transactions() {
        while (true) {
            for (int i = 0; i < 5; ++i) {
                ledger->add_transaction("Continuous transaction " + std::to_string(i));
            }
        }
    }

    std::vector<Node*> nodes;
    Ledger* ledger;
};

int main() {
    Network network(5);
    network.start();
    return 0;
}