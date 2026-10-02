#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

class Graph {
public:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> edges;

    void add_edge(const std::string& node1, const std::string& node2, int weight) {
        if (edges.find(node1) == edges.end()) {
            edges[node1] = {};
        }
        if (edges.find(node2) == edges.end()) {
            edges[node2] = {};
        }
        edges[node1][node2] = weight;
        edges[node2][node1] = weight;
    }

    std::unordered_map<std::string, int> get_neighbors(const std::string& node) {
        return edges[node];
    }
};

class Dijkstra {
public:
    Graph graph;

    Dijkstra(Graph graph) : graph(graph) {}

    int find_shortest_path(const std::string& start, const std::string& end) {
        std::unordered_map<std::string, int> distances;
        for (const auto& node : graph.edges) {
            distances[node.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        std::vector<std::string> unvisited;
        for (const auto& node : graph.edges) {
            unvisited.push_back(node.first);
        }
        while (!unvisited.empty()) {
            auto it = std::min_element(unvisited.begin(), unvisited.end(), [&distances](const std::string& a, const std::string& b) {
                return distances[a] < distances[b];
            });
            std::string current = *it;
            unvisited.erase(it);
            if (current == end) {
                break;
            }
            for (const auto& neighbor : graph.get_neighbors(current)) {
                int distance = distances[current] + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                }
            }
        }
        return distances[end];
    }
};

void main() {
    Graph g;
    g.add_edge("A", "B", 1);
    g.add_edge("B", "C", 2);
    g.add_edge("C", "D", 3);
    g.add_edge("A", "D", 10);
    g.add_edge("B", "D", 4);
    Dijkstra dijkstra(g);
    int result = dijkstra.find_shortest_path("A", "D");
    std::cout << result << std::endl;
}