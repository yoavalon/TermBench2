#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) {
        V = vertices;
        graph.resize(vertices);
    }

    void add_edge(int u, int v, int weight) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
};

std::vector<int> dijkstra(Graph graph, int src) {
    std::vector<int> dist(graph.V, std::numeric_limits<int>::max());
    dist[src] = 0;
    std::vector<bool> visited(graph.V, false);

    auto min_distance = [&dist, &visited, &graph]() -> int {
        int min_val = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int v = 0; v < graph.V; ++v) {
            if (dist[v] < min_val && !visited[v]) {
                min_val = dist[v];
                min_index = v;
            }
        }
        return min_index;
    };

    for (int i = 0; i < graph.V; ++i) {
        int u = min_distance();
        visited[u] = true;
        for (const auto& [v, weight] : graph.graph[u]) {
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

void non_terminating_dijkstra(Graph graph, int start) {
    while (true) {
        auto result = dijkstra(graph, start);
        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
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
    non_terminating_dijkstra(g, 0);
    return 0;
}