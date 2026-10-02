#include <iostream>
#include <map>

void process_ledger() {
    std::map<int, std::map<std::string, int>> ledger;
    while (true) {
        std::map<std::string, int> entry = {{"data", 0}, {"timestamp", 1}};
        ledger[ledger.size()] = entry;
        for (auto& pair : ledger) {
            pair.second["timestamp"] += 1;
        }
    }
}

int main() {
    process_ledger();
    return 0;
}