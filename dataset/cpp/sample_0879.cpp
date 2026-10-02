#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int weight) {
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }
};

class ShortestPath {
public:
    Graph graph;

    ShortestPath(Graph g) : graph(g) {}

    int min_distance(std::vector<int>& dist, std::vector<bool>& sptSet) {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int v = 0; v < graph.V; v++) {
            if (dist[v] < min && !sptSet[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(graph.V, std::numeric_limits<int>::max());
        dist[src] = 0;
        std::vector<bool> sptSet(graph.V, false);
        for (int count = 0; count < graph.V; count++) {
            int u = min_distance(dist, sptSet);
            sptSet[u] = true;
            for (const auto& pair : graph.graph[u]) {
                int v = pair.first;
                int weight = pair.second;
                if (!sptSet[v] && dist[u] != std::numeric_limits<int>::max() && (dist[u] + weight < dist[v])) {
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
    ShortestPath sp(g);
    std::vector<int> result = sp.dijkstra(0);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
}