#include <iostream>
#include <map>
#include <vector>

std::map<std::string, int> update_ledger(std::map<std::string, int> state, const std::map<std::string, int>& transaction) {
    state[transaction.at("to")] += transaction.at("amount");
    state[transaction.at("from")] -= transaction.at("amount");
    return state;
}

bool validate_transaction(const std::map<std::string, int>& state, const std::map<std::string, int>& transaction) {
    return state.at(transaction.at("from")) >= transaction.at("amount");
}

void main() {
    std::map<std::string, int> ledger = {{"A", 100}, {"B", 0}, {"C", 0}};
    std::vector<std::map<std::string, int>> transactions = {
        {{"from", "A"}, {"to", "B"}, {"amount", 30}},
        {{"from", "B"}, {"to", "C"}, {"amount", 20}}
    };
    for (const auto& tx : transactions) {
        if (validate_transaction(ledger, tx)) {
            ledger = update_ledger(ledger, tx);
        }
    }
    while (true) {
        std::map<std::string, int> new_tx = {{"from", "C"}, {"to", "A"}, {"amount", 10}};
        if (validate_transaction(ledger, new_tx)) {
            ledger = update_ledger(ledger, new_tx);
        }
    }
}