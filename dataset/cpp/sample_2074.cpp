#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) {
        V = vertices;
        graph = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
    }

    void add_edge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
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

    std::vector<int> dijkstra(int src) {
        std::vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        std::vector<bool> spt_set(V, false);
        for (int cout = 0; cout < V; cout++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] > 0 && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
};

Graph process_graph() {
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
    return g;
}

void main() {
    Graph g = process_graph();
    std::vector<int> distances = g.dijkstra(0);
    for (int node = 0; node < distances.size(); node++) {
        std::cout << "Distance from 0 to " << node << " is " << distances[node] << std::endl;
    }
}