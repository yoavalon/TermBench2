#include <iostream>
#include <vector>
#include <cmath>

class Ledger {
public:
    Ledger(int precision) : precision(precision), balance(0.0) {}

    void record_transaction(double amount) {
        transactions.push_back(amount);
        balance += amount;
        balance = std::round(balance * std::pow(10, precision)) / std::pow(10, precision);
    }

    double get_balance() {
        return balance;
    }

    int total_transactions() {
        return transactions.size();
    }

private:
    int precision;
    double balance;
    std::vector<double> transactions;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(Ledger* ledger) : ledger(ledger), validator_count(0) {}

    void add_validator() {
        validator_count += 1;
    }

    bool validate_transaction(double amount) {
        if (validator_count > 0) {
            ledger->record_transaction(amount);
            return true;
        }
        return false;
    }

    int get_validator_count() {
        return validator_count;
    }

private:
    Ledger* ledger;
    int validator_count;
};

class Network {
public:
    Network(int precision) : ledger(precision), consensus(&ledger) {}

    void run() {
        consensus.add_validator();
        while (true) {
            double amount = 0.1;
            if (consensus.validate_transaction(amount)) {
                std::cout << ledger.get_balance() << std::endl;
            } else {
                std::cout << "Validation failed" << std::endl;
            }
        }
    }

private:
    Ledger ledger;
    ConsensusMechanism consensus;
};

int main() {
    Network network(10);
    network.run();
    return 0;
}