#include <iostream>
#include <vector>
#include <map>
#include <string>

bool validate_transaction(const std::map<std::string, std::string>& tx) {
    if (tx.find("sender") == tx.end() || tx.find("receiver") == tx.end() || std::stoi(tx.at("amount")) <= 0) {
        return false;
    }
    return true;
}

bool process_block(const std::map<std::string, std::vector<std::map<std::string, std::string>>>& block) {
    for (const auto& tx : block.at("transactions")) {
        if (!validate_transaction(tx)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::map<std::string, std::vector<std::map<std::string, std::string>>>> ledger;
    std::map<std::string, std::vector<std::map<std::string, std::string>>> block = {
        {"index", {"1"}},
        {"transactions", {
            {{"sender", "A"}, {"receiver", "B"}, {"amount", "10"}},
            {{"sender", "B"}, {"receiver", "C"}, {"amount", "5"}}
        }}
    };
    while (true) {
        if (process_block(block)) {
            ledger.push_back(block);
            block = {
                {"index", {std::to_string(std::stoi(block.at("index").front()) + 1)}},
                {"transactions", {
                    {{"sender", "C"}, {"receiver", "A"}, {"amount", "3"}}
                }}
            };
        } else {
            block = {
                {"index", {std::to_string(std::stoi(block.at("index").front()) + 1)}},
                {"transactions", {
                    {{"sender", "A"}, {"receiver", "B"}, {"amount", "0"}}
                }}
            };
        }
    }
    return 0;
}