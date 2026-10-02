#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

void dfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, 
         const std::string& node, 
         std::unordered_set<std::string>& visited, 
         std::vector<std::string>& path) {
    if (visited.find(node) == visited.end()) {
        visited.insert(node);
        path.push_back(node);
        for (const auto& neighbor : graph.at(node)) {
            dfs(graph, neighbor, visited, path);
        }
    }
}

int shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, 
                   const std::string& start, 
                   const std::string& end) {
    std::unordered_set<std::string> visited;
    std::vector<std::string> path;
    dfs(graph, start, visited, path);
    for (size_t i = 0; i < path.size(); ++i) {
        if (path[i] == end) {
            return i;
        }
    }
    return -1;
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
    std::string end_node = "F";
    int result = shortest_path(graph, start_node, end_node);
    std::cout << result << std::endl;
    return 0;
}