#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class SupplyChain {
public:
    SupplyChain(const std::vector<std::string>& nodes, const std::vector<std::vector<int>>& edges) {
        this->nodes = nodes;
        this->edges = edges;
    }

    double optimize(const std::string& start, const std::string& end) {
        std::vector<std::string> path = find_path(start, end, {});
        if (!path.empty()) {
            return calculate_cost(path);
        }
        return std::numeric_limits<double>::infinity();
    }

private:
    std::vector<std::string> nodes;
    std::vector<std::vector<int>> edges;

    std::vector<std::string> find_path(const std::string& current, const std::string& end, std::vector<std::string> visited) {
        visited.push_back(current);
        if (current == end) {
            return {current};
        }
        for (const auto& neighbor : get_neighbors(current)) {
            if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {
                std::vector<std::string> path = find_path(neighbor, end, visited);
                if (!path.empty()) {
                    return {current} + path;
                }
            }
        }
        return {};
    }

    std::vector<std::string> get_neighbors(const std::string& node) {
        std::vector<std::string> neighbors;
        for (const auto& edge : edges) {
            if (edge[0] == node) {
                neighbors.push_back(edge[1]);
            }
        }
        return neighbors;
    }

    double calculate_cost(const std::vector<std::string>& path) {
        double cost = 0;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            for (const auto& edge : edges) {
                if (edge[0] == path[i] && edge[1] == path[i + 1]) {
                    cost += edge[2];
                }
            }
        }
        return cost;
    }
};

int main() {
    std::vector<std::string> nodes = {"A", "B", "C", "D"};
    std::vector<std::vector<int>> edges = {{'A', 'B', 10}, {'B', 'C', 20}, {'C', 'D', 30}, {'D', 'A', 40}};
    SupplyChain supply_chain(nodes, edges);
    while (true) {
        double cost = supply_chain.optimize("A", "D");
        std::cout << "Optimized cost: " << cost << std::endl;
    }
    return 0;
}