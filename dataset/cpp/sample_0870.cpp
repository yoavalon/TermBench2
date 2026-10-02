#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<std::string>& nodes, const std::unordered_map<std::string, std::unordered_map<std::string, int>>& edges, int demand)
        : nodes(nodes), edges(edges), demand(demand), optimized_path() {}

    std::vector<std::string> find_optimal_path(const std::string& start, const std::string& end, std::vector<std::string> path = {}) {
        path.push_back(start);
        if (start == end) {
            return path;
        }
        if (edges.find(start) == edges.end()) {
            return {};
        }
        std::vector<std::string> shortest;
        for (const auto& node : edges.at(start)) {
            if (std::find(path.begin(), path.end(), node.first) == path.end()) {
                std::vector<std::string> newpath = find_optimal_path(node.first, end, path);
                if (!newpath.empty()) {
                    if (shortest.empty() || newpath.size() < shortest.size()) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    int calculate_supply(const std::vector<std::string>& path) {
        int supply = 0;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            supply += edges.at(path[i]).at(path[i + 1]);
        }
        return supply;
    }

    void optimize() {
        for (const auto& start : nodes) {
            for (const auto& end : nodes) {
                if (start != end) {
                    std::vector<std::string> path = find_optimal_path(start, end);
                    if (!path.empty() && demand <= calculate_supply(path)) {
                        optimized_path = path;
                        return;
                    }
                }
            }
        }
    }

    std::vector<std::string> optimized_path;

private:
    std::vector<std::string> nodes;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> edges;
    int demand;
};

int main() {
    std::vector<std::string> nodes = {"A", "B", "C", "D"};
    std::unordered_map<std::string, std::unordered_map<std::string, int>> edges = {
        {"A", {{"B", 10}, {"C", 5}}},
        {"B", {{"D", 8}}},
        {"C", {{"D", 12}}},
        {"D", {}}
    };
    int demand = 15;
    SupplyChainOptimizer optimizer(nodes, edges, demand);
    optimizer.optimize();
    for (const auto& node : optimizer.optimized_path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}