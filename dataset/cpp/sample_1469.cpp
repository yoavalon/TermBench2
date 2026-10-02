#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) : V(vertices), graph(vertices, std::vector<int>(vertices, 0)) {}

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
        int min = std::numeric_limits<int>::max();
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
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        dist[src] = 0;
        std::vector<bool> spt_set(V, false);
        for (int count = 0; count < V; count++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !spt_set[v] && dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        return dist;
    }
};

class Router {
public:
    Graph graph;

    Router(Graph g) : graph(g) {}

    std::vector<int> find_shortest_paths(int start) {
        return graph.dijkstra(start);
    }
};

class Network {
public:
    Graph graph;
    Router router;

    Network(int vertices) : graph(vertices), router(graph) {}

    void connect_nodes(int u, int v, int weight) {
        graph.add_edge(u, v, weight);
    }

    std::vector<int> shortest_paths_from(int node) {
        return router.find_shortest_paths(node);
    }
};

int main() {
    Network network(5);
    network.connect_nodes(0, 1, 10);
    network.connect_nodes(0, 3, 5);
    network.connect_nodes(1, 2, 1);
    network.connect_nodes(1, 3, 2);
    network.connect_nodes(1, 4, 3);
    network.connect_nodes(2, 4, 1);
    network.connect_nodes(3, 2, 4);
    network.connect_nodes(3, 4, 2);
    network.connect_nodes(4, 2, 6);
    network.connect_nodes(4, 0, 7);
    std::vector<int> paths = network.shortest_paths_from(0);
    for (int path : paths) {
        std::cout << path << " ";
    }
    return 0;
}