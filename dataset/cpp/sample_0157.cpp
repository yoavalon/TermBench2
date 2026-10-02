#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

std::vector<char> bfs(const std::unordered_map<char, std::vector<char>>& graph, char start, char end) {
    std::queue<std::pair<char, std::vector<char>>> queue;
    queue.push({start, {start}});
    std::unordered_set<char> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            if (node == end) {
                return path;
            }
            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push({neighbor, path});
                    path.push_back(neighbor);
                }
            }
        }
    }
    return {};
}

int find_shortest_path(const std::unordered_map<char, std::vector<char>>& graph, char start, char end) {
    std::vector<char> path = bfs(graph, start, end);
    if (!path.empty()) {
        return path.size() - 1;
    }
    return -1;
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };
    char start = 'A';
    char end = 'F';
    int result = find_shortest_path(graph, start, end);
    std::cout << result << std::endl;
    return 0;
}