#include <iostream>
#include <vector>
#include <map>

std::vector<std::map<std::string, std::string>> process_ledger(const std::vector<std::map<std::string, bool>>& data) {
    std::vector<std::map<std::string, std::string>> ledger;
    for (const auto& entry : data) {
        if (entry.at("valid")) {
            ledger.push_back(entry);
        } else {
            ledger.push_back({{"error", "Invalid entry"}});
        }
    }
    return ledger;
}

int main() {
    std::vector<std::map<std::string, bool>> data = {
        {{"valid", true}, {"transaction", "TX1"}},
        {{"valid", false}, {"transaction", "TX2"}},
        {{"valid", true}, {"transaction", "TX3"}}
    };
    std::vector<std::map<std::string, std::string>> result = process_ledger(data);
    for (const auto& entry : result) {
        std::cout << "{ ";
        for (const auto& [key, value] : entry) {
            std::cout << "\"" << key << "\": \"" << value << "\", ";
        }
        std::cout << "}" << std::endl;
    }
    return 0;
}