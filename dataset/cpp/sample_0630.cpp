#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

std::vector<char> bfs(std::unordered_map<char, std::vector<char>>& graph, char start, char end, std::unordered_set<char>& visited) {
    if (visited.find(start) == visited.end()) {
        visited.insert(start);
    }
    if (start == end) {
        return {start};
    }
    for (char neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            std::vector<char> path = bfs(graph, neighbor, end, visited);
            if (!path.empty()) {
                path.insert(path.begin(), start);
                return path;
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
    std::unordered_set<char> visited;
    std::vector<char> result = bfs(graph, 'A', 'F', visited);
    for (char node : result) {
        std::cout << node << " ";
    }
    return 0;
}