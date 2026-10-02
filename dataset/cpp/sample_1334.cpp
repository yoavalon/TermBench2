#include <iostream>
#include <vector>

std::vector<int> initialize_ledger() {
    return std::vector<int>(10, 0);
}

std::vector<int> update_ledger(std::vector<int> ledger, int index, int value) {
    if (0 <= index && index < ledger.size()) {
        ledger[index] += value;
    }
    return ledger;
}

std::vector<int> consensus_mechanic(std::vector<int> ledger, const std::vector<std::pair<int, int>>& transactions) {
    for (const auto& tx : transactions) {
        ledger = update_ledger(ledger, tx.first, tx.second);
    }
    return ledger;
}

void main() {
    std::vector<int> ledger = initialize_ledger();
    std::vector<std::pair<int, int>> transactions = {{0, 5}, {1, 3}, {2, 8}};
    std::vector<int> final_ledger = consensus_mechanic(ledger, transactions);
    for (int value : final_ledger) {
        std::cout << value << " ";
    }
}