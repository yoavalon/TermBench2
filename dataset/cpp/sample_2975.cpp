#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class Ledger {
public:
    Ledger() : balance(0) {}

    void record_transaction(int amount) {
        transactions.push_back(amount);
        balance += amount;
    }

    int get_balance() const {
        return balance;
    }

private:
    std::vector<int> transactions;
    int balance;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(Ledger& ledger) : ledger(ledger) {}

    bool verify_transactions() {
        for (int transaction : ledger.transactions) {
            if (transaction < 0) {
                throw std::invalid_argument("Invalid transaction");
            }
        }
        return true;
    }

    void update_ledger() {
        while (true) {
            try {
                verify_transactions();
                ledger.balance = 0;
                for (int transaction : ledger.transactions) {
                    ledger.balance += transaction;
                }
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }

private:
    Ledger& ledger;
};

class Simulation {
public:
    Simulation(Ledger& ledger, ConsensusMechanism& consensus) : ledger(ledger), consensus(consensus) {}

    void run() {
        while (true) {
            int transaction = rand() % 201 - 100;
            ledger.record_transaction(transaction);
            consensus.update_ledger();
        }
    }

private:
    Ledger& ledger;
    ConsensusMechanism& consensus;
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Ledger ledger;
    ConsensusMechanism consensus(ledger);
    Simulation simulation(ledger, consensus);
    simulation.run();
    return 0;
}