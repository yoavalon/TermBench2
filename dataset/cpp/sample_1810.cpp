#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

int find_shortest_path(std::unordered_map<int, std::vector<int>>& graph, int start, int end) {
    std::queue<std::pair<int, int>> queue;
    std::unordered_set<int> visited;
    queue.push({start, 0});
    while (!queue.empty()) {
        auto [node, dist] = queue.front();
        queue.pop();
        if (node == end) {
            return dist;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push({neighbor, dist + 1});
                }
            }
        }
    }
    return -1; // Return -1 if no path is found
}

int main() {
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2}},
        {1, {2, 3}},
        {2, {3, 4}},
        {3, {4}},
        {4, {}}
    };
    std::cout << find_shortest_path(graph, 0, 4) << std::endl;
    return 0;
}