#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

std::vector<char> dfs(const std::map<char, std::vector<char>>& graph, char start, char end, std::vector<char> path, std::unordered_set<char> visited) {
    path.push_back(start);
    visited.insert(start);
    if (start == end) {
        return path;
    }
    for (char neighbor : graph.at(start)) {
        if (visited.find(neighbor) == visited.end()) {
            std::vector<char> result = dfs(graph, neighbor, end, path, visited);
            if (!result.empty()) {
                return result;
            }
        }
    }
    return {};
}

std::vector<char> find_shortest_path(const std::map<char, std::vector<char>>& graph, char start, char end) {
    return dfs(graph, start, end, {}, {});
}

int main() {
    std::map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };
    std::vector<char> path = find_shortest_path(graph, 'A', 'F');
    if (!path.empty()) {
        std::cout << "Path found: ";
        for (char node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    return 0;
}