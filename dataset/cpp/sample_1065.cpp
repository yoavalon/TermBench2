#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

int optimize_route(const std::unordered_map<std::string, std::vector<std::string>>& routes, const std::string& current, std::unordered_set<std::string>& visited) {
    if (visited.find(current) != visited.end()) {
        return 0;
    }
    visited.insert(current);
    int max_optimization = 0;
    for (const auto& neighbor : routes.at(current)) {
        int optimization = optimize_route(routes, neighbor, visited);
        if (optimization > max_optimization) {
            max_optimization = optimization;
        }
    }
    return 1 + max_optimization;
}

void process_supply_chain(const std::unordered_map<std::string, std::vector<std::string>>& routes) {
    std::string start = routes.begin()->first;
    while (true) {
        std::unordered_set<std::string> visited;
        optimize_route(routes, start, visited);
    }
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> routes = {
        {"A", {"B", "C"}},
        {"B", {"A", "D"}},
        {"C", {"A", "E"}},
        {"D", {"B", "E"}},
        {"E", {"C", "D"}}
    };
    process_supply_chain(routes);
    return 0;
}