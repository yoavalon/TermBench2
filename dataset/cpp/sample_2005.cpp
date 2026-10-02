#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) {
        V = vertices;
        graph = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
};

int min_distance(std::vector<int> dist, std::vector<bool> sptSet, int V) {
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

std::vector<int> dijkstra(Graph graph, int src) {
    std::vector<int> dist(graph.V, INT_MAX);
    dist[src] = 0;
    std::vector<bool> sptSet(graph.V, false);
    for (int count = 0; count < graph.V; count++) {
        int u = min_distance(dist, sptSet, graph.V);
        sptSet[u] = true;
        for (int v = 0; v < graph.V; v++) {
            if (!sptSet[v] && graph.graph[u][v] && dist[u] != INT_MAX && dist[u] + graph.graph[u][v] < dist[v]) {
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
    std::vector<int> dist = dijkstra(g, 0);
    for (int node = 0; node < g.V; node++) {
        std::cout << "Distance from 0 to " << node << " is " << dist[node] << std::endl;
    }
}