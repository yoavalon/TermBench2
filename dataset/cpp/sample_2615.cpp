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

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int min_distance(std::vector<int> dist, std::vector<bool> spt_set) {
        int min = INT_MAX;
        int min_index = 0;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min && spt_set[v] == false) {
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
                if (graph[u][v] && spt_set[v] == false && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
};

Graph generate_sequence(int n) {
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = abs(i - j);
            g.add_edge(i, j, weight);
        }
    }
    return g;
}

int find_shortest_path(Graph graph, int src, int dest) {
    std::vector<int> path_lengths = graph.dijkstra(src);
    return path_lengths[dest];
}

int main() {
    int n = 10;
    Graph graph = generate_sequence(n);
    int src = 0;
    int dest = n - 1;
    int result = find_shortest_path(graph, src, dest);
    std::cout << "Shortest path from " << src << " to " << dest << ": " << result << std::endl;
    return 0;
}