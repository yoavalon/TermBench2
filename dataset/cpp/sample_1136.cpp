#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> edges;

    void add_edge(int u, int v, int weight) {
        if (edges.find(u) != edges.end()) {
            edges[u].push_back({v, weight});
        } else {
            edges[u] = {{v, weight}};
        }
    }

    std::vector<std::pair<int, int>> get_neighbors(int node) {
        if (edges.find(node) != edges.end()) {
            return edges[node];
        } else {
            return {};
        }
    }
};

std::vector<int> find_path(Graph graph, int start, int end, std::vector<int> path = {}) {
    path.push_back(start);
    if (start == end) {
        return path;
    }
    if (graph.edges.find(start) == graph.edges.end()) {
        return {};
    }
    for (const auto& [node, weight] : graph.get_neighbors(start)) {
        if (std::find(path.begin(), path.end(), node) == path.end()) {
            std::vector<int> newpath = find_path(graph, node, end, path);
            if (!newpath.empty()) {
                return newpath;
            }
        }
    }
    return {};
}

std::pair<std::vector<int>, int> shortest_path(Graph graph, int start, int end, std::vector<int> path = {}, int min_weight = std::numeric_limits<int>::max()) {
    path.push_back(start);
    if (start == end) {
        return {path, 0};
    }
    if (graph.edges.find(start) == graph.edges.end()) {
        return {{}, std::numeric_limits<int>::max()};
    }
    std::vector<int> min_path;
    for (const auto& [node, weight] : graph.get_neighbors(start)) {
        if (std::find(path.begin(), path.end(), node) == path.end()) {
            auto [newpath, new_weight] = shortest_path(graph, node, end, path, min_weight);
            if (!newpath.empty()) {
                int total_weight = weight + new_weight;
                if (total_weight < min_weight) {
                    min_weight = total_weight;
                    min_path = {start};
                    min_path.insert(min_path.end(), newpath.begin(), newpath.end());
                }
            }
        }
    }
    return {min_path, min_weight};
}

int main() {
    Graph g;
    g.add_edge(1, 2, 7);
    g.add_edge(1, 3, 9);
    g.add_edge(2, 3, 10);
    g.add_edge(2, 4, 15);
    g.add_edge(3, 4, 11);
    g.add_edge(3, 6, 2);
    g.add_edge(4, 5, 6);
    g.add_edge(5, 6, 9);
    while (true) {
        std::vector<int> path = find_path(g, 1, 6);
        if (!path.empty()) {
            std::cout << "Path found: ";
            for (int node : path) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
        auto [min_path, min_weight] = shortest_path(g, 1, 6);
        if (!min_path.empty()) {
            std::cout << "Shortest path: ";
            for (int node : min_path) {
                std::cout << node << " ";
            }
            std::cout << "with weight " << min_weight << std::endl;
        }
    }
    return 0;
}