#include <iostream>
#include <vector>
#include <cmath>

class Ledger {
public:
    Ledger(const std::vector<double>& data) : data(data), balance(0.0) {}

    void update_balance(double amount) {
        balance += amount;
    }

    double get_balance() const {
        return balance;
    }

private:
    std::vector<double> data;
    double balance;
};

class Consensus {
public:
    Consensus(Ledger& ledger) : ledger(ledger), threshold(0.0001) {}

    bool verify_transaction(double amount) {
        if (std::abs(amount) > threshold) {
            return true;
        }
        return false;
    }

    void process_transactions(const std::vector<double>& transactions) {
        for (double transaction : transactions) {
            if (verify_transaction(transaction)) {
                ledger.update_balance(transaction);
            }
        }
    }

private:
    Ledger& ledger;
    double threshold;
};

class Analysis {
public:
    Analysis(Ledger& ledger) : ledger(ledger) {}

    double calculate_precision_error() {
        double balance = ledger.get_balance();
        double error = balance - static_cast<int>(balance);
        return error;
    }

private:
    Ledger& ledger;
};

int main() {
    std::vector<double> data = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
    Ledger ledger(data);
    Consensus consensus(ledger);
    Analysis analysis(ledger);
    std::vector<double> transactions = {5e-05, -2e-05, 3e-05, 0.00015, -1e-05};
    consensus.process_transactions(transactions);
    double error = analysis.calculate_precision_error();
    std::cout << "Floating point precision error: " << error << std::endl;
    return 0;
}