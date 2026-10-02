#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) {
        V = vertices;
        graph.resize(vertices, std::vector<int>(vertices, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
};

void dijkstra(Graph& graph, int src, std::vector<int>& dist, std::vector<bool>& visited, std::vector<int>& path) {
    if (all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
        return;
    }
    int u = INT_MAX;
    for (int v = 0; v < graph.V; ++v) {
        if (!visited[v] && (u == INT_MAX || dist[v] < dist[u])) {
            u = v;
        }
    }
    visited[u] = true;
    for (int v = 0; v < graph.V; ++v) {
        if (!visited[v] && graph.graph[u][v] != 0) {
            if (dist[u] + graph.graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.graph[u][v];
                path[v] = u;
            }
        }
    }
    dijkstra(graph, src, dist, visited, path);
}

std::vector<int> find_shortest_path(Graph& graph, int src, int dest) {
    std::vector<int> dist(graph.V, INT_MAX);
    dist[src] = 0;
    std::vector<bool> visited(graph.V, false);
    std::vector<int> path(graph.V, -1);
    dijkstra(graph, src, dist, visited, path);
    if (dist[dest] == INT_MAX) {
        return {};
    }
    std::vector<int> result;
    while (dest != -1) {
        result.insert(result.begin(), dest);
        dest = path[dest];
    }
    return result;
}

int main() {
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
    std::vector<int> path = find_shortest_path(g, 0, 4);
    for (int vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    return 0;
}