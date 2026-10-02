#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

void dfs(const std::map<std::string, std::vector<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited, std::vector<std::string>& path) {
    visited.insert(node);
    path.push_back(node);
    for (const auto& neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited, path);
        }
    }
}

std::vector<std::string> shortest_path(const std::map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::unordered_set<std::string> visited;
    std::vector<std::string> path;
    dfs(graph, start, visited, path);
    return std::find(path.begin(), path.end(), end) != path.end() ? path : std::vector<std::string>();
}

int main() {
    std::map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E"}}
    };
    std::string start_node = "A";
    std::string end_node = "F";
    std::vector<std::string> result = shortest_path(graph, start_node, end_node);
    for (const auto& node : result) {
        std::cout << node << " ";
    }
    return 0;
}