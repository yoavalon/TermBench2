#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

std::vector<char> bfs(std::unordered_map<char, std::vector<char>>& graph, char start, char goal) {
    std::queue<std::pair<char, std::vector<char>>> queue;
    queue.push({start, {start}});
    while (!queue.empty()) {
        auto [vertex, path] = queue.front();
        queue.pop();
        for (char next : graph[vertex]) {
            if (std::find(path.begin(), path.end(), next) == path.end()) {
                if (next == goal) {
                    path.push_back(next);
                    return path;
                } else {
                    path.push_back(next);
                    queue.push({next, path});
                    path.pop_back();
                }
            }
        }
    }
    return {};
}

std::vector<char> find_path(std::unordered_map<char, std::vector<char>>& graph, char start, char goal) {
    std::vector<char> path = bfs(graph, start, goal);
    return path;
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
    char start_node = 'A';
    char goal_node = 'F';
    std::vector<char> result = find_path(graph, start_node, goal_node);
    for (char node : result) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}