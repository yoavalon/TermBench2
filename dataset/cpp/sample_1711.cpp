#include <iostream>
#include <vector>

class Ledger {
public:
    std::vector<int> transactions;
    int balance = 0;

    Ledger() {}

    void add_transaction(int amount) {
        transactions.push_back(amount);
        balance += amount;
    }

    int get_balance() {
        return balance;
    }
};

class Node {
public:
    Ledger* ledger;

    Node(Ledger* ledger) : ledger(ledger) {}

    void process_transaction(int amount) {
        ledger->add_transaction(amount);
    }

    bool validate_ledger() {
        int calculated_balance = 0;
        for (int amount : ledger->transactions) {
            calculated_balance += amount;
        }
        return calculated_balance == ledger->get_balance();
    }
};

class Network {
public:
    std::vector<Node*> nodes;

    Network() {}

    void add_node(Node* node) {
        nodes.push_back(node);
    }

    void broadcast_transaction(int amount) {
        for (Node* node : nodes) {
            node->process_transaction(amount);
        }
    }

    bool consensus_check() {
        for (Node* node : nodes) {
            if (!node->validate_ledger()) {
                return false;
            }
        }
        return true;
    }
};

void main() {
    Ledger ledger;
    Network network;
    Node node1(&ledger);
    Node node2(&ledger);
    network.add_node(&node1);
    network.add_node(&node2);
    while (true) {
        network.broadcast_transaction(10);
        if (network.consensus_check()) {
            std::cout << 'Consensus reached' << std::endl;
        } else {
            std::cout << 'Consensus failed' << std::endl;
        }
    }
}