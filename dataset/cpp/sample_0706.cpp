#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

std::vector<std::string> dfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited, const std::string& target) {
    if (node == target) {
        return {node};
    }
    visited.insert(node);
    for (const auto& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            std::vector<std::string> path = dfs(graph, neighbor, visited, target);
            if (!path.empty()) {
                return {node} + path;
            }
        }
    }
    return {};
}

std::vector<std::string> find_shortest_path(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& target) {
    std::unordered_set<std::string> visited;
    return dfs(graph, start, visited, target);
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    std::string start_node = "A";
    std::string target_node = "F";
    std::vector<std::string> path = find_shortest_path(graph, start_node, target_node);
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    return 0;
}