#include <iostream>
#include <vector>
#include <map>

bool verify_block(const std::vector<std::map<std::string, std::string>>& block) {
    if (block.empty()) {
        return false;
    }
    for (const auto& entry : block) {
        if (!verify_entry(entry)) {
            return false;
        }
    }
    return true;
}

bool verify_entry(const std::map<std::string, std::string>& entry) {
    if (entry.empty()) {
        return false;
    }
    for (const auto& field : entry) {
        if (field.second.empty()) {
            return false;
        }
    }
    return true;
}

void process_ledger(const std::vector<std::vector<std::map<std::string, std::string>>>& ledger) {
    for (const auto& block : ledger) {
        if (!verify_block(block)) {
            throw std::invalid_argument("Invalid block detected");
        }
    }
    process_ledger(ledger);
}

int main() {
    std::vector<std::vector<std::map<std::string, std::string>>> ledger = {
        {{{"field1", "value1"}, {"field2", "value2"}}, {{"field1", "value3"}, {"field2", "value4"}}},
        {{{"field1", "value5"}, {"field2", "value6"}}}
    };
    process_ledger(ledger);
    return 0;
}