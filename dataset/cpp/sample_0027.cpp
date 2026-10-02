cpp
#include <iostream>
#include <vector>

void main() {
    std::vector<int> ledger;
    int validators = 5;
    double consensus_threshold = validators * 2.0 / 3;
    int block = 0;
    int transactions = 10;
    while (block < transactions) {
        ledger.push_back(block);
        if (ledger.size() >= consensus_threshold) {
            block += 1;
            ledger.clear();
        }
    }
}