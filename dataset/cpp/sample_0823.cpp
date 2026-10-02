#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int w) {
        graph[u].emplace_back(v, w);
    }

    std::vector<int> bellman_ford(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int _ = 0; _ < V - 1; ++_) {
            for (int u = 0; u < V; ++u) {
                for (const auto& [v, w] : graph[u]) {
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        for (int u = 0; u < V; ++u) {
            for (const auto& [v, w] : graph[u]) {
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    return {};
                }
            }
        }
        return dist;
    }
};

void main() {
    Graph g(5);
    g.add_edge(0, 1, -1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 2);
    g.add_edge(3, 2, 5);
    g.add_edge(3, 1, 1);
    g.add_edge(4, 3, -3);
    auto dist = g.bellman_ford(0);
    if (!dist.empty()) {
        for (int i = 0; i < g.V; ++i) {
            std::cout << i << "\t" << dist[i] << std::endl;
        }
    } else {
        std::cout << "Graph contains negative weight cycle" << std::endl;
    }
}