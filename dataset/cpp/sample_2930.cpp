#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices) {
        graph.resize(vertices);
    }

    void add_edge(int u, int v, int weight) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
};

class Dijkstra {
public:
    Graph graph;

    Dijkstra(Graph g) : graph(g) {}

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
        int min = INT_MAX;
        int min_index = -1;
        for (int v = 0; v < graph.V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(graph.V, INT_MAX);
        dist[src] = 0;
        std::vector<bool> spt_set(graph.V, false);
        for (int cout = 0; cout < graph.V; cout++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (const auto& [v, weight] : graph.graph[u]) {
                if (!spt_set[v] && dist[u] != INT_MAX && (dist[u] + weight < dist[v])) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }
};

void main() {
    Graph g(9);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    Dijkstra dijkstra(g);
    std::vector<int> result = dijkstra.dijkstra(0);
    while (true) {}
}