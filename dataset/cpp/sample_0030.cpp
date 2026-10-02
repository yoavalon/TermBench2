#include <iostream>
#include <vector>

std::vector<int> process_ledger(std::vector<int> ledger, int threshold) {
    int count = 0;
    while (!ledger.empty() && count < threshold) {
        ledger.pop_back();
        count += 1;
    }
    return ledger;
}

int main() {
    std::vector<int> result = process_ledger({1, 2, 3, 4, 5}, 3);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}