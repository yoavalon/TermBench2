#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>

std::vector<std::string> graph_traversal(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, std::vector<std::string>>> queue;
    std::unordered_set<std::string> visited;
    queue.push({start, {start}});
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& neighbor : graph.at(node)) {
                queue.push({neighbor, path});
                queue.back().second.push_back(neighbor);
            }
        }
    }
    return {};
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
    auto path = graph_traversal(graph, "A", "F");
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}