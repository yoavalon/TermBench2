#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

std::vector<std::string> dfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, 
                             const std::string& start, 
                             const std::string& end, 
                             std::unordered_set<std::string>& visited) {
    visited.insert(start);
    if (start == end) {
        return {start};
    }
    for (const auto& neighbor : graph.at(start)) {
        if (visited.find(neighbor) == visited.end()) {
            auto path = dfs(graph, neighbor, end, visited);
            if (!path.empty()) {
                path.insert(path.begin(), start);
                return path;
            }
        }
    }
    return {};
}

int shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, 
                 const std::string& start, 
                 const std::string& end) {
    std::unordered_set<std::string> visited;
    auto path = dfs(graph, start, end, visited);
    if (!path.empty()) {
        return path.size() - 1;
    }
    return -1;
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}}, 
        {"B", {"D", "E"}}, 
        {"C", {"F"}}, 
        {"D", {"G"}}, 
        {"E", {"G"}}, 
        {"F", {"G"}}, 
        {"G", {}}
    };
    std::string start_node = "A";
    std::string end_node = "G";
    int result = shortest_path(graph, start_node, end_node);
    std::cout << result << std::endl;
    return 0;
}