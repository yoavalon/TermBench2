#include <iostream>
#include <vector>

std::vector<int> update_ledger(std::vector<int> ledger, int transaction) {
    ledger.push_back(transaction);
    return ledger;
}

bool validate_transaction(const std::vector<int>& ledger, int transaction) {
    return std::find(ledger.begin(), ledger.end(), transaction) == ledger.end();
}

int main() {
    std::vector<int> ledger;
    std::vector<int> transactions = {1, 2, 3, 4, 5, 3, 6, 7};
    for (int transaction : transactions) {
        if (validate_transaction(ledger, transaction)) {
            ledger = update_ledger(ledger, transaction);
        } else {
            std::cout << 'Transaction already exists: ' << transaction << std::endl;
            break;
        }
    }
    std::cout << 'Final ledger: ';
    for (int entry : ledger) {
        std::cout << entry << ' ';
    }
    std::cout << std::endl;
    return 0;
}