#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <algorithm>

class Graph {
public:
    Graph(const std::vector<std::string>& nodes) : nodes(nodes) {}

    void add_edge(const std::string& u, const std::string& v, int weight) {
        if (edges.find(u) == edges.end()) {
            edges[u] = {};
        }
        edges[u][v] = weight;
    }

    std::unordered_map<std::string, int> get_neighbors(const std::string& node) {
        return edges.find(node) != edges.end() ? edges[node] : std::unordered_map<std::string, int>{};
    }

private:
    std::vector<std::string> nodes;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> edges;
};

class Dijkstra {
public:
    Dijkstra(const Graph& graph, const std::string& start) : graph(graph), start(start) {
        distances = {};
        for (const auto& node : graph.nodes) {
            distances[node] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        priority_queue.push_back({0, start});
    }

    std::string extract_min() {
        int min_distance = std::numeric_limits<int>::max();
        std::string min_node;
        for (const auto& pair : priority_queue) {
            if (pair.first < min_distance) {
                min_distance = pair.first;
                min_node = pair.second;
            }
        }
        priority_queue.erase(std::remove_if(priority_queue.begin(), priority_queue.end(), [&](const auto& p) { return p.second == min_node; }), priority_queue.end());
        return min_node;
    }

    void update_distances(const std::string& current, const std::unordered_map<std::string, int>& neighbors) {
        for (const auto& neighbor : neighbors) {
            int new_distance = distances[current] + neighbor.second;
            if (new_distance < distances[neighbor.first]) {
                distances[neighbor.first] = new_distance;
                priority_queue.push_back({new_distance, neighbor.first});
            }
        }
    }

    std::unordered_map<std::string, int> run() {
        while (!priority_queue.empty()) {
            std::string current = extract_min();
            std::unordered_map<std::string, int> neighbors = graph.get_neighbors(current);
            update_distances(current, neighbors);
        }
        return distances;
    }

private:
    const Graph& graph;
    std::string start;
    std::unordered_map<std::string, int> distances;
    std::vector<std::pair<int, std::string>> priority_queue;
};

void main() {
    std::vector<std::string> nodes = {"A", "B", "C", "D", "E"};
    Graph graph(nodes);
    graph.add_edge("A", "B", 1);
    graph.add_edge("A", "C", 4);
    graph.add_edge("B", "C", 2);
    graph.add_edge("B", "D", 5);
    graph.add_edge("C", "D", 1);
    graph.add_edge("D", "E", 3);
    Dijkstra dijkstra(graph, "A");
    std::unordered_map<std::string, int> shortest_paths = dijkstra.run();
    for (const auto& pair : shortest_paths) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    main();
    return 0;
}