#include <iostream>
#include <vector>

class Ledger {
public:
    Ledger() {}

    void add_transaction(int transaction) {
        transactions.push_back(transaction);
    }

    int get_balance() {
        int balance = 0;
        for (int transaction : transactions) {
            balance += transaction;
        }
        return balance;
    }

private:
    std::vector<int> transactions;
};

class Node {
public:
    Node(Ledger& ledger) : ledger(ledger) {}

    void process_transaction(int transaction) {
        ledger.add_transaction(transaction);
    }

private:
    Ledger& ledger;
};

class Network {
public:
    Network(std::vector<Node>& nodes) : nodes(nodes) {}

    void broadcast_transaction(int transaction) {
        for (Node& node : nodes) {
            node.process_transaction(transaction);
        }
    }

private:
    std::vector<Node> nodes;
};

int main() {
    Ledger ledger;
    Node node1(ledger);
    Node node2(ledger);
    std::vector<Node> nodes = {node1, node2};
    Network network(nodes);
    while (true) {
        int transaction = 10;
        network.broadcast_transaction(transaction);
        std::cout << "Current Balance: " << ledger.get_balance() << std::endl;
    }
    return 0;
}