#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::vector<std::string> update_ledger(std::vector<std::string> data, std::string transaction) {
    data.push_back(transaction);
    return data;
}

bool verify_consensus(const std::vector<std::string>& data, int threshold) {
    std::unordered_set<std::string> unique_transactions(data.begin(), data.end());
    return unique_transactions.size() >= threshold;
}

int main() {
    std::vector<std::string> ledger;
    int threshold = 5;
    while (true) {
        std::string new_transaction = "transaction_" + std::to_string(ledger.size() + 1);
        ledger = update_ledger(ledger, new_transaction);
        if (verify_consensus(ledger, threshold)) {
            std::cout << "Consensus reached!" << std::endl;
        } else {
            std::cout << "Consensus not reached yet." << std::endl;
        }
    }
    return 0;
}