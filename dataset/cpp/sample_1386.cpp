#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_map>

std::vector<char> bfs(std::unordered_map<char, std::vector<char>>& graph, char start, char end) {
    std::queue<std::pair<char, std::vector<char>>> queue;
    queue.push({start, {start}});
    std::unordered_set<char> visited;
    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (char neighbor : graph[node]) {
                queue.push({neighbor, path});
                path.push_back(neighbor);
            }
        }
    }
    return {};
}

int find_shortest_path(std::unordered_map<char, std::vector<char>>& graph, char start, char end) {
    std::vector<char> path = bfs(graph, start, end);
    if (!path.empty()) {
        return path.size() - 1;
    }
    return -1;
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };
    char start = 'A';
    char end = 'F';
    std::cout << find_shortest_path(graph, start, end) << std::endl;
    return 0;
}