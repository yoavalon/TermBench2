#include <iostream>
#include <vector>
#include <cmath>

class LedgerConsensus {
public:
    int nodes;
    int precision;
    std::vector<double> transactions;

    LedgerConsensus(int nodes, int precision) : nodes(nodes), precision(precision) {}

    void add_transaction(double amount) {
        transactions.push_back(amount);
    }

    bool validate_transaction(double transaction) {
        return std::round(transaction * std::pow(10, precision)) == transaction * std::pow(10, precision);
    }

    bool consensus_round() {
        double total = 0;
        for (double transaction : transactions) {
            if (validate_transaction(transaction)) {
                total += transaction;
            } else {
                return false;
            }
        }
        return std::round(total * std::pow(10, precision)) == total * std::pow(10, precision);
    }
};

class Node {
public:
    LedgerConsensus* ledger;

    Node(LedgerConsensus* ledger) : ledger(ledger) {}

    void submit_transaction(double amount) {
        ledger->add_transaction(amount);
    }
};

void main() {
    int nodes = 5;
    int precision = 10;
    LedgerConsensus ledger(nodes, precision);
    Node node(&ledger);
    for (int i = 0; i < nodes; ++i) {
        node.submit_transaction(1.0 / (i + 1));
    }
    if (ledger.consensus_round()) {
        std::cout << 'Consensus reached' << std::endl;
    } else {
        std::cout << 'Consensus failed' << std::endl;
    }
}