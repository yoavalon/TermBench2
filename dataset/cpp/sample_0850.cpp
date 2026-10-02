#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;

    void add_edge(int u, int v, int weight) {
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }
};

std::unordered_map<int, int> dijkstra(Graph& graph, int start) {
    std::unordered_map<int, int> distances;
    for (const auto& [node, _] : graph.graph) {
        distances[node] = INT_MAX;
    }
    distances[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> priority_queue;
    priority_queue.emplace(0, start);
    while (!priority_queue.empty()) {
        int current_distance = priority_queue.top().first;
        int current_node = priority_queue.top().second;
        priority_queue.pop();
        if (current_distance > distances[current_node]) {
            continue;
        }
        for (const auto& [neighbor, weight] : graph.graph[current_node]) {
            int distance = current_distance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                priority_queue.emplace(distance, neighbor);
            }
        }
    }
    return distances;
}

int find_shortest_path(Graph& graph, int start, int end) {
    std::unordered_map<int, int> distances = dijkstra(graph, start);
    return distances[end];
}

int main() {
    Graph g;
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    int shortest_path = find_shortest_path(g, 0, 4);
    std::cout << shortest_path << std::endl;
    return 0;
}