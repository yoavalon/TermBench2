#include <iostream>
#include <map>
#include <vector>

std::map<std::string, int> update_ledger(std::map<std::string, int> data, std::map<std::string, int> node) {
    for (const auto& pair : data) {
        data[pair.first] += node[pair.first];
    }
    return data;
}

std::map<std::string, int> simulate_consensus(const std::vector<std::map<std::string, int>>& nodes) {
    std::map<std::string, int> ledger = nodes[0];
    for (const auto& node : nodes) {
        ledger = update_ledger(ledger, node);
    }
    return ledger;
}

void main() {
    std::vector<std::map<std::string, int>> nodes = {
        {{"A", 1}, {"B", 2}, {"C", 3}},
        {{"A", 4}, {"B", 5}, {"C", 6}},
        {{"A", 7}, {"B", 8}, {"C", 9}}
    };
    while (true) {
        std::map<std::string, int> ledger = simulate_consensus(nodes);
        for (const auto& pair : ledger) {
            std::cout << pair.first << ": " << pair.second << " ";
        }
        std::cout << std::endl;
    }
}