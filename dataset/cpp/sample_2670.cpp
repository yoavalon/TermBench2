#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int w) {
        graph[u].push_back(std::make_pair(v, w));
        graph[v].push_back(std::make_pair(u, w));
    }
};

int min_distance(std::vector<int>& dist, std::vector<bool>& sptSet) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < dist.size(); v++) {
        if (dist[v] < min && sptSet[v] == false) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

std::vector<int> dijkstra(Graph& graph, int src) {
    std::vector<int> dist(graph.V, INT_MAX);
    dist[src] = 0;
    std::vector<bool> sptSet(graph.V, false);
    for (int _ = 0; _ < graph.V; _++) {
        int u = min_distance(dist, sptSet);
        sptSet[u] = true;
        for (const auto& [v, weight] : graph.graph[u]) {
            if (!sptSet[v] && dist[u] != INT_MAX && (dist[u] + weight < dist[v])) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
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
    std::vector<int> dist = dijkstra(g, 0);
    for (int node = 0; node < dist.size(); node++) {
        std::cout << "Distance to node " << node << " is " << dist[node] << std::endl;
    }
    return 0;
}