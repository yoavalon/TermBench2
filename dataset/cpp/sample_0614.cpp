#include <iostream>
#include <vector>

bool validate_ledger(const std::vector<int>& data, int index = 0) {
    if (index >= data.size() - 1) {
        return true;
    }
    if (data[index] != data[index + 1]) {
        return false;
    }
    return validate_ledger(data, index + 1);
}

int main() {
    std::vector<int> ledger_data = {1, 1, 1, 1, 1};
    std::cout << validate_ledger(ledger_data) << std::endl;
    return 0;
}