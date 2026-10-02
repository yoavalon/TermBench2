#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

int find_shortest_path(const std::unordered_map<std::string, std::unordered_map<std::string, double>>& graph, const std::string& start, const std::string& end) {
    std::vector<std::tuple<std::string, double, std::unordered_set<std::string>>> queue = {{start, 0.0, {start}}};
    while (!queue.empty()) {
        auto [node, cost, visited] = queue.front();
        queue.erase(queue.begin());
        if (node == end) {
            return cost;
        }
        for (const auto& [neighbor, weight] : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                std::unordered_set<std::string> new_visited = visited;
                new_visited.insert(neighbor);
                queue.push_back({neighbor, cost + weight, new_visited});
            }
        }
    }
    return -1;
}

int main() {
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph = {
        {"A", {{"B", 1.0}, {"C", 4.0}}},
        {"B", {{"A", 1.0}, {"D", 2.0}}},
        {"C", {{"A", 4.0}, {"D", 1.0}}},
        {"D", {{"B", 2.0}, {"C", 1.0}}}
    };
    std::cout << find_shortest_path(graph, "A", "D") << std::endl;
    return 0;
}