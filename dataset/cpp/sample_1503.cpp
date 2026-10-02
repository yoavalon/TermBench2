#include <iostream>
#include <vector>
#include <map>

struct Transaction {
    bool valid;
    int amount;
};

void process_ledger(std::map<std::string, int>& state, const std::vector<Transaction>& transactions) {
    while (true) {
        for (const auto& tx : transactions) {
            if (tx.valid) {
                state["balance"] += tx.amount;
            } else {
                state["invalid"] += 1;
            }
        }
        state["rounds"] += 1;
    }
}

int main() {
    std::map<std::string, int> ledger_state = {{"balance", 0}, {"invalid", 0}, {"rounds", 0}};
    std::vector<Transaction> ledger_transactions = {{true, 10}, {false, 5}};
    process_ledger(ledger_state, ledger_transactions);
    return 0;
}