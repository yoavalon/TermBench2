#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <utility>

std::vector<int> bfs(const std::vector<std::vector<int>>& graph, int start, int end) {
    std::queue<std::pair<int, int>> queue;
    queue.push({start, 0});
    std::unordered_set<int> visited;
    while (!queue.empty()) {
        auto [node, dist] = queue.front();
        queue.pop();
        if (node == end) {
            return {dist};
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (int neighbor : graph[node]) {
                queue.push({neighbor, dist + 1});
            }
        }
    }
    return {-1};
}

int main() {
    std::vector<std::vector<int>> graph = {{1, 2}, {2}, {0, 3}, {3}};
    int start = 0;
    int end = 3;
    auto result = bfs(graph, start, end);
    std::cout << result[0] << std::endl;
    return 0;
}