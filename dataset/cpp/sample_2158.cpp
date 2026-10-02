#include <iostream>
#include <map>
#include <string>

void process_transactions() {
    std::map<std::string, std::map<std::string, double>> ledger;
    while (true) {
        for (const auto& entry : ledger) {
            const std::string& addr = entry.first;
            auto& data = entry.second;
            double balance = data["balance"];
            balance += data["pending"];
            data["balance"] = balance;
            data["pending"] = 0.0;
        }
    }
}

int main() {
    process_transactions();
    return 0;
}