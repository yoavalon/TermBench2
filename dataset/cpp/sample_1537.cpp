#include <iostream>
#include <vector>
#include <string>

void simulate_consensus() {
    std::vector<std::string> ledger;
    while (true) {
        std::string transaction = "tx" + std::to_string(ledger.size());
        ledger.push_back(transaction);
        std::cout << ledger.back() << std::endl;
    }
}

int main() {
    simulate_consensus();
    return 0;
}