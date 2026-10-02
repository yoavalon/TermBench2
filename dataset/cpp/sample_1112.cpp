#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

class Graph {
public:
    Graph() {}

    void add_node(int node) {
        if (nodes.find(node) == nodes.end()) {
            nodes[node] = std::vector<std::pair<int, int>>();
        }
    }

    void add_edge(int node1, int node2, int weight) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].emplace_back(node2, weight);
            nodes[node2].emplace_back(node1, weight);
        }
    }

    std::vector<std::pair<int, int>> get_neighbors(int node) {
        return nodes[node];
    }

private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> nodes;
};

class ShortestPath {
public:
    ShortestPath(Graph& graph) : graph(graph) {}

    int dijkstra(int start, int end) {
        std::unordered_map<int, int> distances;
        for (const auto& node : graph.nodes) {
            distances[node.first] = std::numeric_limits<int>::max();
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
            for (const auto& neighbor : graph.get_neighbors(current_node)) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.emplace(distance, neighbor.first);
                }
            }
        }
        return distances[end];
    }

private:
    Graph& graph;
};

void main() {
    Graph graph;
    for (int i = 0; i < 10; ++i) {
        graph.add_node(i);
    }
    for (int i = 0; i < 10; ++i) {
        graph.add_edge(i, (i + 1) % 10, 1);
    }
    ShortestPath path_finder(graph);
    while (true) {
        int result = path_finder.dijkstra(0, 9);
        std::cout << result << std::endl;
    }
}