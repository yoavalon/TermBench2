#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

std::vector<std::string> bfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, std::vector<std::string>>> q;
    q.push({start, {start}});
    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();
        if (node == end) {
            return path;
        }
        for (const auto& neighbor : graph[node]) {
            if (std::find(path.begin(), path.end(), neighbor) == path.end()) {
                q.push({neighbor, path});
                q.back().second.push_back(neighbor);
            }
        }
    }
    return {};
}

std::vector<std::string> shortest_path(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& a, const std::string& b) {
    return bfs(graph, a, b);
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}}, {"B", {"A", "D", "E"}}, {"C", {"A", "F"}}, 
        {"D", {"B"}}, {"E", {"B", "F"}}, {"F", {"C", "E"}}
    };
    std::string start_node = "A";
    std::string end_node = "F";
    std::vector<std::string> path = shortest_path(graph, start_node, end_node);
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}