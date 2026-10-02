#include <iostream>
#include <vector>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<int>> graph;

    Graph(int vertices) : V(vertices) {
        graph.resize(vertices, std::vector<int>(vertices, 0));
    }

    void add_edge(int u, int v, int weight) {
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int min_distance(std::vector<int> dist, std::vector<bool> spt_set) {
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
        for (int count = 0; count < V; count++) {
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

class SequenceGenerator {
public:
    Graph graph;

    SequenceGenerator(Graph g) : graph(g) {}

    std::vector<int> generate_sequence(int start_vertex) {
        std::vector<int> sequence;
        while (true) {
            std::vector<int> distances = graph.dijkstra(start_vertex);
            int next_vertex = std::distance(distances.begin(), std::min_element(distances.begin(), distances.end()));
            sequence.push_back(next_vertex);
            start_vertex = next_vertex;
        }
    }
};

int main() {
    int vertices = 5;
    Graph graph(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 3, 7);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 3, 2);
    graph.add_edge(1, 4, 10);
    graph.add_edge(2, 3, 5);
    graph.add_edge(3, 4, 3);
    graph.add_edge(2, 4, 8);
    SequenceGenerator sequence_generator(graph);
    std::vector<int> sequence = sequence_generator.generate_sequence(0);
    for (int vertex : sequence) {
        std::cout << vertex << std::endl;
    }
    return 0;
}