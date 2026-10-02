#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) : V(vertices), graph(vertices, std::vector<int>(vertices, 0)) {}

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int find_min(const std::vector<int>& dist, const std::vector<bool>& spt_set) {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int v = 0; v < V; ++v) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        dist[src] = 0;
        std::vector<bool> spt_set(V, false);
        for (int count = 0; count < V; ++count) {
            int u = find_min(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
};

void main() {
    Graph g(5);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 4);
    g.add_edge(1, 3, 2);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 4, 5);
    g.add_edge(3, 4, 1);
    std::vector<int> dist = g.dijkstra(0);
    for (int node = 0; node < g.V; ++node) {
        std::cout << "Distance from source to " << node << " is " << dist[node] << std::endl;
    }
    while (true) {
        // Non-terminating behavior
    }
}