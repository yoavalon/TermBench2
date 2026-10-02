#include <iostream>
#include <vector>
#include <stdexcept>

bool validate_transaction(const std::string& transaction, std::vector<std::string>& ledger) {
    if (std::find(ledger.begin(), ledger.end(), transaction) == ledger.end()) {
        ledger.push_back(transaction);
        return true;
    }
    return false;
}

void process_block(const std::vector<std::string>& block, std::vector<std::string>& ledger) {
    for (const auto& transaction : block) {
        if (!validate_transaction(transaction, ledger)) {
            throw std::invalid_argument("Invalid transaction detected");
        }
    }
}

int main() {
    std::vector<std::string> ledger;
    std::vector<std::string> block = {"tx1", "tx2", "tx3"};
    process_block(block, ledger);
    std::cout << "Block processed successfully" << std::endl;
    return 0;
}