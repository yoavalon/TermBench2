#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

std::vector<std::string> bfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, std::vector<std::string>>> queue;
    queue.push({start, {start}});
    std::unordered_set<std::string> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        visited.insert(node);
        if (node == end) {
            return path;
        }
        for (const auto& neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                queue.push({neighbor, path});
                queue.back().second.push_back(neighbor);
            }
        }
    }
    return {};
}

std::vector<std::string> shortest_path(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    return bfs(graph, start, end);
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
    std::vector<std::string> result = shortest_path(graph, start_node, end_node);
    for (const auto& node : result) {
        std::cout << node << " ";
    }
    return 0;
}