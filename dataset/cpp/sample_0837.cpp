#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>

class LogisticsOptimizer {
public:
    LogisticsOptimizer(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& data) : data(data) {}

    std::vector<std::string> find_optimal_route(const std::string& current, const std::string& destination, std::unordered_set<std::string>& visited) {
        if (current == destination) {
            return {destination};
        }
        visited.insert(current);
        auto neighbors = data.find(current);
        if (neighbors == data.end()) {
            return {};
        }
        for (const auto& neighbor : neighbors->second) {
            if (visited.find(neighbor.first) == visited.end()) {
                auto path = find_optimal_route(neighbor.first, destination, visited);
                if (!path.empty()) {
                    return {current} + path;
                }
            }
        }
        return {};
    }

    int calculate_cost(const std::vector<std::string>& path) {
        int cost = 0;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            auto it = data.find(path[i]);
            if (it != data.end()) {
                auto it2 = it->second.find(path[i + 1]);
                if (it2 != it->second.end()) {
                    cost += it2->second;
                }
            }
        }
        return cost;
    }

    std::pair<int, std::vector<std::string>> optimize(const std::string& start, const std::string& end) {
        std::unordered_set<std::string> visited;
        auto path = find_optimal_route(start, end, visited);
        if (!path.empty()) {
            return {calculate_cost(path), path};
        }
        return {std::numeric_limits<int>::max(), {}};
    }

private:
    const std::unordered_map<std::string, std::unordered_map<std::string, int>>& data;
};

void main() {
    std::unordered_map<std::string, std::unordered_map<std::string, int>> data = {
        {"A", {{"B", 10}, {"C", 15}}},
        {"B", {{"A", 10}, {"D", 20}}},
        {"C", {{"A", 15}, {"D", 30}}},
        {"D", {{"B", 20}, {"C", 30}}}
    };
    LogisticsOptimizer optimizer(data);
    auto result = optimizer.optimize("A", "D");
    std::cout << "Optimal Cost: " << result.first << std::endl;
    std::cout << "Optimal Path: ";
    for (const auto& node : result.second) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}