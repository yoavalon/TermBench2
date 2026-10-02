#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

void non_terminating_graph_traversal(const std::unordered_map<int, std::vector<int>>& graph) {
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        for (int neighbor : graph.at(current)) {
            queue.push(neighbor);
        }
    }
}

int main() {
    std::unordered_map<int, std::vector<int>> graph = {{0, {1, 2}}, {1, {2}}, {2, {0}}};
    non_terminating_graph_traversal(graph);
    return 0;
}