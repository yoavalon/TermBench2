#include <iostream>
#include <vector>
#include <cmath>

class Ledger {
public:
    Ledger() : balance(0.0) {}

    void record_transaction(double amount) {
        records.push_back(amount);
        balance += amount;
    }

    double get_balance() {
        return balance;
    }

private:
    std::vector<double> records;
    double balance;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(Ledger& ledger) : ledger(ledger), threshold(0.01) {}

    bool verify_transactions() {
        double total = 0.0;
        for (double record : ledger.records) {
            total += record;
        }
        if (std::abs(total - ledger.balance) < threshold) {
            return true;
        }
        return false;
    }

private:
    Ledger& ledger;
    double threshold;
};

class Node {
public:
    Node(Ledger& ledger, ConsensusMechanism& consensus) : ledger(ledger), consensus(consensus) {}

    bool process_transactions(const std::vector<double>& transactions) {
        for (double transaction : transactions) {
            ledger.record_transaction(transaction);
        }
        return consensus.verify_transactions();
    }

private:
    Ledger& ledger;
    ConsensusMechanism& consensus;
};

int main() {
    Ledger ledger;
    ConsensusMechanism consensus(ledger);
    Node node(ledger, consensus);
    std::vector<double> transactions = {0.001, -0.002, 0.003, -0.004, 0.005, -0.006, 0.007, -0.008, 0.009, -0.01};
    while (true) {
        if (node.process_transactions(transactions)) {
            std::cout << 'Consensus reached.' << std::endl;
        } else {
            std::cout << 'Consensus not reached.' << std::endl;
        }
    }
    return 0;
}