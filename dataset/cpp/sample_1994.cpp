#include <iostream>
#include <map>
#include <vector>

bool validate_transaction(double amount, double balance) {
    if (amount <= balance) {
        return true;
    }
    return false;
}

double process_transaction(double amount, double balance) {
    if (validate_transaction(amount, balance)) {
        return balance - amount;
    }
    return balance;
}

std::map<std::string, double> update_ledger(const std::vector<std::pair<double, std::string>>& transactions, std::map<std::string, double> ledger) {
    for (const auto& transaction : transactions) {
        double amount = transaction.first;
        std::string account = transaction.second;
        ledger[account] = process_transaction(amount, ledger[account]);
    }
    return ledger;
}

int main() {
    std::map<std::string, double> ledger = {{"A", 1000.0}, {"B", 500.0}};
    std::vector<std::pair<double, std::string>> transactions = {{150.0, "A"}, {200.0, "B"}, {300.0, "A"}};
    std::map<std::string, double> updated_ledger = update_ledger(transactions, ledger);
    for (const auto& entry : updated_ledger) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
    return 0;
}