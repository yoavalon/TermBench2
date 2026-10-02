#include <iostream>
#include <vector>
#include <map>

std::vector<std::map<std::string, std::string>> update_ledger(std::vector<std::map<std::string, std::string>> ledger, std::map<std::string, std::string> transaction) {
    ledger.push_back(transaction);
    return ledger;
}

int main() {
    std::vector<std::map<std::string, std::string>> ledger;
    while (true) {
        std::map<std::string, std::string> transaction = {{"amount", "100"}, {"from", "userA"}, {"to", "userB"}};
        ledger = update_ledger(ledger, transaction);
        for (const auto& entry : ledger) {
            std::cout << "{ ";
            for (const auto& pair : entry) {
                std::cout << pair.first << ": " << pair.second << ", ";
            }
            std::cout << "}" << std::endl;
        }
    }
    return 0;
}