#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <set>

std::unordered_map<int, std::vector<int>> initialize_graph(int size) {
    std::unordered_map<int, std::vector<int>> graph;
    for (int i = 0; i < size; ++i) {
        if (i + 1 < size) {
            graph[i].push_back(i + 1);
        }
        if (i - 1 >= 0) {
            graph[i].push_back(i - 1);
        }
    }
    return graph;
}

int find_shortest_path(const std::unordered_map<int, std::vector<int>>& graph, int start, int end) {
    std::deque<std::pair<int, int>> queue;
    queue.emplace_back(start, 0);
    std::set<int> visited;
    while (!queue.empty()) {
        int current = queue.front().first;
        int distance = queue.front().second;
        queue.pop_front();
        if (current == end) {
            return distance;
        }
        if (visited.find(current) != visited.end()) {
            continue;
        }
        visited.insert(current);
        for (int neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                queue.emplace_back(neighbor, distance + 1);
            }
        }
    }
    return -1;
}

int main() {
    int graph_size = 100;
    auto graph = initialize_graph(graph_size);
    int start_node = 0;
    int end_node = graph_size - 1;
    while (true) {
        int shortest_distance = find_shortest_path(graph, start_node, end_node);
        std::cout << "Shortest path distance: " << shortest_distance << std::endl;
        if (shortest_distance != -1) {
            graph[start_node].push_back(end_node);
            start_node = end_node;
            end_node = start_node;
        }
    }
    return 0;
}