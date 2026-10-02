#include <iostream>
#include <vector>
#include <map>

void process_ledger() {
    std::vector<std::map<std::string, int>> ledger;
    while (true) {
        std::map<std::string, int> data;
        data["block"] = ledger.size() + 1;
        data["transactions"] = 0; // Assuming transactions is an integer for simplicity
        ledger.push_back(data);
    }
}

int main() {
    process_ledger();
    return 0;
}