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

    int min_distance(std::vector<int>& dist, std::vector<bool>& spt_set) {
        int min = INT_MAX;
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

class Sequence {
public:
    Graph graph;
    int start;

    Sequence(Graph g, int start) : graph(g), start(start) {}

    std::vector<int> generate_sequence() {
        std::vector<int> dist = graph.dijkstra(start);
        std::vector<int> sequence;
        for (int i = 0; i < dist.size(); i++) {
            if (i != start) {
                sequence.push_back(dist[i]);
            }
        }
        return sequence;
    }
};

void main() {
    int V = 9;
    Graph g(V);
    g.graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    Sequence seq(g, 0);
    std::vector<int> result = seq.generate_sequence();
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
}