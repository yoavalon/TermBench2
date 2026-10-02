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
        graph[v][u] = weight;
    }
};

class ShortestPath {
public:
    Graph graph;
    int V;

    ShortestPath(Graph g) : graph(g), V(g.V) {}

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        std::vector<bool> spt_set(V, false);

        for (int _ = 0; _ < V; ++_) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; ++v) {
                if (!spt_set[v] && graph.graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph.graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph.graph[u][v];
                }
            }
        }
        return dist;
    }

    int min_distance(const std::vector<int>& dist, const std::vector<bool>& spt_set) {
        int min = INT_MAX, min_index = -1;
        for (int v = 0; v < V; ++v) {
            if (dist[v] < min && !spt_set[v]) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
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

    ShortestPath shortest_path_finder(g);
    std::vector<int> distances = shortest_path_finder.dijkstra(0);

    while (true) {
        for (int i = 0; i < distances.size(); ++i) {
            std::cout << distances[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < distances.size(); ++i) {
            distances[i] += 0.0001;
        }
    }
}