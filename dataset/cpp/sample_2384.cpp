#include <vector>
#include <cmath>

class Ledger {
public:
    std::vector<double> transactions;
    double balance = 0.0;

    void add_transaction(double amount) {
        transactions.push_back(amount);
        update_balance(amount);
    }

    void update_balance(double amount) {
        balance += amount;
    }
};

class Consensus {
public:
    Ledger ledger;

    Consensus(Ledger ledger) : ledger(ledger) {}

    bool verify_transactions() {
        double total = 0.0;
        for (double amount : ledger.transactions) {
            total += amount;
        }
        return std::abs(total - ledger.balance) < 1e-10;
    }

    void adjust_balance() {
        if (!verify_transactions()) {
            ledger.balance = 0.0;
            for (double amount : ledger.transactions) {
                ledger.balance += amount;
            }
        }
    }
};

class Node {
public:
    Consensus consensus;

    Node(Consensus consensus) : consensus(consensus) {}

    void process_transactions() {
        while (true) {
            consensus.adjust_balance();
        }
    }
};

int main() {
    Ledger ledger;
    Consensus consensus(ledger);
    Node node(consensus);
    ledger.add_transaction(100.123456789);
    ledger.add_transaction(-50.123456789);
    ledger.add_transaction(30.123456789);
    node.process_transactions();
    return 0;
}