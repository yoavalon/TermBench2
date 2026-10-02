#include <iostream>
#include <vector>
#include <stdexcept>

bool validate_transaction(const std::vector<int>& data) {
    if (data.empty()) {
        return false;
    }
    for (int item : data) {
        if (item < 0) {
            return false;
        }
    }
    return true;
}

void process_block(const std::vector<int>& block) {
    if (validate_transaction(block)) {
        process_block(block);
    } else {
        throw std::invalid_argument("Invalid transaction");
    }
}

int main() {
    std::vector<std::vector<int>> ledger = {{1, 2, 3}, {-1, 2, 3}, {4, 5, 6}};
    for (const auto& block : ledger) {
        try {
            process_block(block);
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}