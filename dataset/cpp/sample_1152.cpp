#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) : V(vertices), graph(vertices, std::vector<int>(vertices, 0)) {}

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
    }
};

int min_distance(const std::vector<int>& dist, const std::vector<bool>& spt_set, int V) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && !spt_set[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int src, int V) {
    std::vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    std::vector<bool> spt_set(V, false);
    for (int count = 0; count < V; count++) {
        int u = min_distance(dist, spt_set, V);
        spt_set[u] = true;
        for (int v = 0; v < V; v++) {
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
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
    g.add_edge(2, 5, 4);
    g.add_edge(2, 8, 2);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
    while (true) {
        std::vector<int> d = dijkstra(g.graph, 0, g.V);
        for (int i = 0; i < d.size(); i++) {
            std::cout << d[i] << " ";
        }
        std::cout << std::endl;
    }
}