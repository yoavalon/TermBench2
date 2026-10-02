#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

std::vector<std::string> bfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, std::vector<std::string>>> queue;
    queue.push({start, {start}});
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        for (const auto& neighbor : graph.at(node)) {
            if (neighbor == end) {
                path.push_back(neighbor);
                return path;
            } else if (std::find(path.begin(), path.end(), neighbor) == path.end()) {
                queue.push({neighbor, path});
                path.push_back(neighbor);
            }
        }
    }
    return {};
}

std::vector<std::string> find_shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
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
    std::string start = "A";
    std::string end = "F";
    std::vector<std::string> path = find_shortest_path(graph, start, end);
    if (!path.empty()) {
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i];
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    return 0;
}