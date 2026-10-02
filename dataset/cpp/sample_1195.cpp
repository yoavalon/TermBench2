#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int w) {
        graph[u].push_back(std::make_pair(v, w));
        graph[v].push_back(std::make_pair(u, w));
    }

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        dist[src] = 0;
        std::vector<bool> visited(V, false);
        while (true) {
            int min_dist = std::numeric_limits<int>::max();
            int u = -1;
            for (int i = 0; i < V; ++i) {
                if (!visited[i] && dist[i] < min_dist) {
                    min_dist = dist[i];
                    u = i;
                }
            }
            if (u == -1) {
                break;
            }
            visited[u] = true;
            for (const auto& [v, weight] : graph[u]) {
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        return dist;
    }

private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;
};

void non_terminating_graph_traversal() {
    Graph g(10);
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
        std::vector<int> dist = g.dijkstra(0);
        for (int d : dist) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    non_terminating_graph_traversal();
    return 0;
}