#include <iostream>
#include <vector>
#include <limits>

std::vector<std::vector<float>> init_matrix(int size) {
    return std::vector<std::vector<float>>(size, std::vector<float>(size, std::numeric_limits<float>::infinity()));
}

void update_distance(const std::vector<std::vector<float>>& graph, std::vector<float>& dist, int src, int size) {
    for (int v = 0; v < size; ++v) {
        if (graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]) {
            dist[v] = dist[src] + graph[src][v];
        }
    }
}

std::vector<float> shortest_path(const std::vector<std::vector<float>>& graph, int src, int size) {
    std::vector<float> dist(size, std::numeric_limits<float>::infinity());
    dist[src] = 0;
    for (int i = 0; i < size - 1; ++i) {
        update_distance(graph, dist, src, size);
    }
    return dist;
}

void main() {
    std::vector<std::vector<float>> graph = {
        {0, 5, std::numeric_limits<float>::infinity(), 10},
        {std::numeric_limits<float>::infinity(), 0, 3, std::numeric_limits<float>::infinity()},
        {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), 0, 1},
        {std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), 0}
    };
    int size = graph.size();
    std::vector<float> result = shortest_path(graph, 0, size);
    for (float val : result) {
        std::cout << val << " ";
    }
}