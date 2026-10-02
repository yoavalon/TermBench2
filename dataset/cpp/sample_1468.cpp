#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>

class Graph {
public:
    std::map<int, std::vector<std::pair<int, int>>> nodes;

    void add_node(int node) {
        if (nodes.find(node) == nodes.end()) {
            nodes[node] = {};
        }
    }

    void add_edge(int from_node, int to_node, int weight) {
        if (nodes.find(from_node) != nodes.end()) {
            nodes[from_node].push_back({to_node, weight});
        }
    }
};

int dijkstra(Graph graph, int start, int end) {
    std::map<int, int> distances;
    for (const auto& node : graph.nodes) {
        distances[node.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priority_queue;
    priority_queue.push({0, start});
    while (!priority_queue.empty()) {
        int current_distance = priority_queue.top().first;
        int current_node = priority_queue.top().second;
        priority_queue.pop();
        if (current_distance > distances[current_node]) {
            continue;
        }
        for (const auto& neighbor : graph.nodes[current_node]) {
            int distance = current_distance + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                priority_queue.push({distance, neighbor.first});
            }
        }
    }
    return distances[end];
}

int main() {
    Graph graph;
    graph.add_node(1);
    graph.add_node(2);
    graph.add_node(3);
    graph.add_node(4);
    graph.add_edge(1, 2, 10);
    graph.add_edge(1, 3, 15);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 4, 12);
    graph.add_edge(3, 4, 10);
    std::cout << dijkstra(graph, 1, 4) << std::endl;
    return 0;
}