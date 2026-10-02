#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int w) {
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
};

class ShortestPath {
public:
    Graph graph;
    std::vector<int> dist;
    std::vector<int> parent;

    ShortestPath(Graph g) : graph(g), dist(g.V, INT_MAX), parent(g.V, -1) {}

    void bellman_ford(int src) {
        dist[src] = 0;
        for (int i = 0; i < graph.V - 1; ++i) {
            for (int u = 0; u < graph.V; ++u) {
                for (const auto& [v, weight] : graph.graph[u]) {
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                    }
                }
            }
        }
    }

    std::vector<int> get_shortest_path(int dst) {
        std::vector<int> path;
        if (dist[dst] == INT_MAX) {
            return path;
        }
        while (dst != -1) {
            path.push_back(dst);
            dst = parent[dst];
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};

void main() {
    int V = 5;
    Graph graph(V);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 3, 7);
    graph.add_edge(1, 4, 9);
    graph.add_edge(2, 3, 4);
    graph.add_edge(2, 4, 2);
    graph.add_edge(3, 4, 11);
    graph.add_edge(3, 0, 2);
    graph.add_edge(4, 0, 7);
    ShortestPath shortest_path_finder(graph);
    shortest_path_finder.bellman_ford(0);
    std::vector<int> path = shortest_path_finder.get_shortest_path(4);
    for (int vertex : path) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}