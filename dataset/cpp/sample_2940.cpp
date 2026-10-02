#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b) : a(a), b(b), current(0) {}

    int next_value() {
        current += 1;
        return a * current + b;
    }

private:
    int a;
    int b;
    int current;
};

class LedgerSimulator {
public:
    LedgerSimulator(SequenceGenerator* sequence) : sequence(sequence) {}

    int add_transaction() {
        int value = sequence->next_value();
        transactions.push_back(value);
        return value;
    }

    bool consensus_check() {
        if (transactions.size() > 2) {
            return transactions.back() - transactions[transactions.size() - 2] == sequence->a;
        }
        return false;
    }

private:
    SequenceGenerator* sequence;
    std::vector<int> transactions;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(LedgerSimulator* ledger) : ledger(ledger) {}

    void run() {
        while (true) {
            int new_value = ledger->add_transaction();
            if (ledger->consensus_check()) {
                confirmed.push_back(new_value);
            }
        }
    }

private:
    LedgerSimulator* ledger;
    std::vector<int> confirmed;
};

int main() {
    SequenceGenerator seq(3, 5);
    LedgerSimulator ledger(&seq);
    ConsensusMechanism consensus(&ledger);
    consensus.run();
    return 0;
}