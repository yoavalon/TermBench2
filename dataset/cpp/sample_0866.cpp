#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int v;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) {
        v = vertices;
        graph.resize(vertices, std::vector<int>(vertices, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
};

int min_distance(const std::vector<int>& dist, const std::vector<bool>& visited, int v) {
    int min_val = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < v; i++) {
        if (dist[i] < min_val && !visited[i]) {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int src, int v) {
    std::vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    std::vector<bool> visited(v, false);
    for (int count = 0; count < v; count++) {
        int u = min_distance(dist, visited, v);
        visited[u] = true;
        for (int i = 0; i < v; i++) {
            if (graph[u][i] && !visited[i] && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }
    return dist;
}

void main() {
    int v = 9;
    Graph g(v);
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
    std::vector<int> dist = dijkstra(g.graph, 0, v);
    for (int node = 0; node < v; node++) {
        std::cout << "Distance to " << node << ": " << dist[node] << std::endl;
    }
}