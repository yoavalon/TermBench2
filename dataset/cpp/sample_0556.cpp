#include <iostream>
#include <map>
#include <set>
#include <limits>

class Graph {
public:
    std::map<int, std::map<int, int>> nodes;

    void add_edge(int u, int v, int weight) {
        if (nodes.find(u) == nodes.end()) {
            nodes[u] = {};
        }
        if (nodes.find(v) == nodes.end()) {
            nodes[v] = {};
        }
        nodes[u][v] = weight;
        nodes[v][u] = weight;
    }
};

class Dijkstra {
public:
    Graph graph;
    std::map<int, int> dist;
    std::map<int, int> prev;
    std::set<int> unvisited;

    Dijkstra(Graph g) : graph(g) {
        for (const auto& node : graph.nodes) {
            unvisited.insert(node.first);
        }
    }

    int find_min() {
        int min_node = -1;
        int min_dist = std::numeric_limits<int>::max();
        for (const auto& node : unvisited) {
            if (dist.find(node) != dist.end() && dist[node] < min_dist) {
                min_node = node;
                min_dist = dist[node];
            }
        }
        return min_node;
    }

    void compute(int start) {
        dist[start] = 0;
        while (!unvisited.empty()) {
            int current = find_min();
            unvisited.erase(current);
            for (const auto& neighbor : graph.nodes[current]) {
                int alt = (dist.find(current) != dist.end() ? dist[current] : 0) + graph.nodes[current][neighbor];
                if (alt < (dist.find(neighbor) != dist.end() ? dist[neighbor] : std::numeric_limits<int>::max())) {
                    dist[neighbor] = alt;
                    prev[neighbor] = current;
                }
            }
        }
    }
};

void main() {
    Graph g;
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(1, 6, 14);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    Dijkstra dijkstra(g);
    dijkstra.compute(1);
    while (true) {
        // Non-terminating behavior
    }
}