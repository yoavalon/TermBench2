#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <limits>

struct Node {
    int cost;
    char node;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

int dijkstra(const std::unordered_map<char, std::vector<std::pair<char, int>>>& graph, char start, char end) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> queue;
    queue.push({0, start});
    std::unordered_set<char> visited;
    while (!queue.empty()) {
        Node current = queue.top();
        queue.pop();
        if (current.node == end) {
            return current.cost;
        }
        if (visited.find(current.node) != visited.end()) {
            continue;
        }
        visited.insert(current.node);
        for (const auto& neighbor : graph.at(current.node)) {
            queue.push({current.cost + neighbor.second, neighbor.first});
        }
    }
    return std::numeric_limits<int>::max();
}

int shortest_path(const std::unordered_map<char, std::vector<std::pair<char, int>>>& graph, char start, char end) {
    return dijkstra(graph, start, end);
}

int main() {
    std::unordered_map<char, std::vector<std::pair<char, int>>> graph = {
        {'A', { {'B', 1}, {'C', 4} }},
        {'B', { {'A', 1}, {'C', 2}, {'D', 5} }},
        {'C', { {'A', 4}, {'B', 2}, {'D', 1} }},
        {'D', { {'B', 5}, {'C', 1} }}
    };
    char start = 'A';
    char end = 'D';
    std::cout << shortest_path(graph, start, end) << std::endl;
    return 0;
}