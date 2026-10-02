#include <iostream>
#include <vector>

int process_block(const std::vector<int>& block) {
    int result = 0;
    for (int data : block) {
        result += data;
    }
    return result;
}

std::vector<int> update_ledger(const std::vector<int>& ledger, const std::vector<int>& new_block) {
    std::vector<int> updated_ledger = ledger;
    updated_ledger.push_back(process_block(new_block));
    return updated_ledger;
}

int main() {
    std::vector<int> ledger;
    while (true) {
        std::vector<int> new_block = {1, 2, 3, 4, 5};
        ledger = update_ledger(ledger, new_block);
        for (int value : ledger) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}