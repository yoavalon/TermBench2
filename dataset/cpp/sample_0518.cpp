#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) : V(vertices), graph(vertices, std::vector<int>(vertices, 0)) {}

    void add_edge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
        int min = INT_MAX;
        int min_index = 0;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
};

std::vector<int> dijkstra(Graph graph, int src) {
    std::vector<int> dist(graph.V, INT_MAX);
    dist[src] = 0;
    std::vector<bool> spt_set(graph.V, false);
    for (int count = 0; count < graph.V; count++) {
        int u = graph.min_distance(dist, spt_set);
        spt_set[u] = true;
        for (int v = 0; v < graph.V; v++) {
            if (graph.graph[u][v] && !spt_set[v] && dist[v] > dist[u] + graph.graph[u][v]) {
                dist[v] = dist[u] + graph.graph[u][v];
            }
        }
    }
    return dist;
}

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
    while (true) {
        int src = 0;
        std::vector<int> dist = dijkstra(g, src);
        std::cout << "Vertex \t Distance from Source\n";
        for (int node = 0; node < g.V; node++) {
            std::cout << node << "\t " << dist[node] << "\n";
        }
    }
}