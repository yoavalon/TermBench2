#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <string>

std::vector<std::string> bfs(const std::unordered_map<std::string, std::unordered_set<std::string>>& graph, const std::string& start, const std::string& end) {
    std::deque<std::pair<std::string, std::vector<std::string>>> queue;
    queue.emplace_back(start, std::vector<std::string>{start});
    std::unordered_set<std::string> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop_front();
        if (node == end) {
            return path;
        }
        visited.insert(node);
        for (const auto& neighbor : graph.at(node)) {
            if (visited.find(neighbor) == visited.end()) {
                queue.emplace_back(neighbor, path);
                queue.back().second.push_back(neighbor);
            }
        }
    }
    return {};
}

void main() {
    std::unordered_map<std::string, std::unordered_set<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E"}}
    };
    std::string start_node = "A";
    std::string end_node = "F";
    auto result = bfs(graph, start_node, end_node);
    if (!result.empty()) {
        for (const auto& node : result) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
}