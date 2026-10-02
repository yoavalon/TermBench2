#include <iostream>
#include <vector>
#include <map>

bool validate_node_status(const std::map<std::string, std::string>& node) {
    return node.at("status") == "active" && node.at("consensus") == "reached";
}

bool process_ledger(const std::vector<std::map<std::string, std::map<std::string, std::string>>> ledger, int threshold) {
    for (const auto& block : ledger) {
        if (!validate_node_status(block.at("node"))) {
            return false;
        }
        if (block.at("transactions") > threshold) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::map<std::string, std::map<std::string, std::string>>> ledger_data = {
        {{"node", {{"status", "active"}, {"consensus", "reached"}}}, {"transactions", 100}},
        {{"node", {{"status", "active"}, {"consensus", "reached"}}}, {"transactions", 200}},
        {{"node", {{"status", "active"}, {"consensus", "reached"}}}, {"transactions", 300}}
    };
    int threshold_value = 250;
    bool result = process_ledger(ledger_data, threshold_value);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}