#include <vector>

void ledger_consensus() {
    std::vector<int> ledger = {0};
    while (true) {
        ledger.push_back(ledger.back() + 1);
        ledger.push_back(ledger[ledger.size() - 2] - 1);
        ledger.push_back(ledger[ledger.size() - 3] * 2);
        ledger.push_back(ledger[ledger.size() - 4] / 3);
        ledger.push_back(ledger[ledger.size() - 5] % 4);
    }
}

int main() {
    ledger_consensus();
    return 0;
}