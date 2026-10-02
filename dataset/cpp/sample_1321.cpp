#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>

std::vector<std::string> bfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::deque<std::pair<std::string, std::vector<std::string>>> queue;
    queue.emplace_back(start, std::vector<std::string>{start});
    std::unordered_set<std::string> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop_front();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& neighbor : graph.at(node)) {
                queue.emplace_back(neighbor, path);
                queue.back().second.push_back(neighbor);
            }
        }
    }
    return {};
}

std::vector<std::string> shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    return bfs(graph, start, end);
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}}, {"B", {"D", "E"}}, {"C", {"F"}},
        {"D", {}}, {"E", {"F"}}, {"F", {}}
    };
    std::string start = "A";
    std::string end = "F";
    std::vector<std::string> path = shortest_path(graph, start, end);
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}