#include <iostream>
#include <map>
#include <vector>

std::map<int, int> update_ledger(std::map<int, int> state, const std::map<std::string, int>& transaction) {
    state[transaction.at("id")] = transaction.at("value");
    return state;
}

bool validate_transaction(const std::map<int, int>& state, const std::map<std::string, int>& transaction) {
    if (state.find(transaction.at("id")) != state.end() && state.at(transaction.at("id")) != transaction.at("value")) {
        return false;
    }
    return true;
}

void main() {
    std::map<int, int> ledger;
    std::vector<std::map<std::string, int>> transactions = {
        {{"id", 1}, {"value", 100}},
        {{"id", 2}, {"value", 200}},
        {{"id", 1}, {"value", 150}}
    };
    for (const auto& transaction : transactions) {
        if (validate_transaction(ledger, transaction)) {
            ledger = update_ledger(ledger, transaction);
        }
    }
    for (const auto& entry : ledger) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}