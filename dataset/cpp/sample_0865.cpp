#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int weight) {
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);
    }

    std::vector<int> dijkstra(int start) {
        std::vector<int> distance(V, INT_MAX);
        distance[start] = 0;
        std::vector<bool> visited(V, false);

        auto min_distance = [&distance, &visited]() -> int {
            int min_dist = INT_MAX;
            int min_index = -1;
            for (int v = 0; v < V; ++v) {
                if (!visited[v] && distance[v] < min_dist) {
                    min_dist = distance[v];
                    min_index = v;
                }
            }
            return min_index;
        };

        for (int _ = 0; _ < V; ++_) {
            int u = min_distance();
            visited[u] = true;
            for (const auto& [v, weight] : graph[u]) {
                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        return distance;
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
    int start_vertex = 0;
    std::vector<int> distances = g.dijkstra(start_vertex);
    for (int i = 0; i < g.V; ++i) {
        std::cout << "Distance from " << start_vertex << " to " << i << " is " << distances[i] << std::endl;
    }
}