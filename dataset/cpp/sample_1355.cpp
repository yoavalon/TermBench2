#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

std::vector<char> bfs(std::unordered_map<char, std::vector<char>>& graph, char start, char end) {
    std::queue<std::pair<char, std::vector<char>>> queue;
    queue.push({start, {start}});
    std::set<char> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (char neighbor : graph[node]) {
                path.push_back(neighbor);
                queue.push({neighbor, path});
                path.pop_back();
            }
        }
    }
    return {};
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
    std::vector<char> path = bfs(graph, 'A', 'F');
    for (char c : path) {
        std::cout << c << " ";
    }
    return 0;
}