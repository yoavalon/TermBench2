#include <iostream>
#include <vector>
#include <cmath>

class Ledger {
public:
    Ledger(int precision) : precision(precision) {}

    void add_transaction(double amount) {
        if (transactions.size() > precision) {
            transactions.erase(transactions.begin());
        }
        transactions.push_back(amount);
    }

    double get_average_transaction() {
        if (transactions.empty()) {
            return 0;
        }
        double sum = 0;
        for (double transaction : transactions) {
            sum += transaction;
        }
        return sum / transactions.size();
    }

private:
    std::vector<double> transactions;
    int precision;
};

class ConsensusMechanism {
public:
    ConsensusMechanism(Ledger* ledger) : ledger(ledger) {}

    void update_ledger(double new_amount) {
        ledger->add_transaction(new_amount);
    }

    bool validate_transaction(double amount) {
        double avg_transaction = ledger->get_average_transaction();
        return std::abs(amount - avg_transaction) < ledger->precision;
    }

private:
    Ledger* ledger;
};

class Network {
public:
    Network(int precision) : ledger(precision), consensus_mechanism(&ledger) {}

    bool process_transaction(double amount) {
        if (consensus_mechanism.validate_transaction(amount)) {
            consensus_mechanism.update_ledger(amount);
            return true;
        }
        return false;
    }

private:
    Ledger ledger;
    ConsensusMechanism consensus_mechanism;
};

int main() {
    Network network(5);
    double amounts[] = {10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9, 11.0};
    for (double amount : amounts) {
        if (!network.process_transaction(amount)) {
            std::cout << "Transaction " << amount << " rejected" << std::endl;
        } else {
            std::cout << "Transaction " << amount << " accepted" << std::endl;
        }
    }
    return 0;
}