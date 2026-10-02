#include <iostream>
#include <vector>
#include <limits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) {
        V = vertices;
        graph.resize(vertices, std::vector<int>(vertices, 0));
    }

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min && spt_set[v] == false) {
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

class DataMutator {
public:
    std::vector<std::vector<int>> data;

    DataMutator(const std::vector<std::vector<int>>& data) {
        this->data = data;
    }

    Graph transform() {
        Graph graph(data.size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                graph.graph[i][j] = data[i][j];
            }
        }
        return graph;
    }
};

void main() {
    std::vector<std::vector<int>> data = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    DataMutator mutator(data);
    Graph graph = mutator.transform();
    std::vector<int> dist = graph.dijkstra(0);
    for (int node = 0; node < dist.size(); node++) {
        std::cout << "Distance to " << node << " is " << dist[node] << std::endl;
    }
}