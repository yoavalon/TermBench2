#include <iostream>
#include <vector>
#include <climits>

class Graph {
    int V;
    std::vector<std::vector<int>> graph;

public:
    Graph(int vertices) : V(vertices), graph(vertices, std::vector<int>(vertices, 0)) {}

    void add_edge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    void print_solution(const std::vector<int>& dist) {
        std::cout << "Vertex \tDistance from Source\n";
        for (int node = 0; node < V; node++) {
            std::cout << node << "\t" << dist[node] << "\n";
        }
    }

    int min_distance(const std::vector<int>& dist, const std::vector<bool>& spt_set) {
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

    void dijkstra(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        std::vector<bool> spt_set(V, false);
        for (int cout = 0; cout < V; cout++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        print_solution(dist);
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
    g.dijkstra(0);
}