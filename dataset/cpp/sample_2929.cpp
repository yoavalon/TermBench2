#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <limits>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> nodes;

    void add_node(int node) {
        if (nodes.find(node) == nodes.end()) {
            nodes[node] = {};
        }
    }

    void add_edge(int node1, int node2, int weight = 1) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].emplace_back(node2, weight);
            nodes[node2].emplace_back(node1, weight);
        }
    }

    std::vector<std::pair<int, int>> get_neighbors(int node) {
        if (nodes.find(node) != nodes.end()) {
            return nodes[node];
        }
        return {};
    }
};

class PathFinder {
public:
    Graph graph;

    PathFinder(Graph graph) : graph(graph) {}

    int dijkstra(int start, int end) {
        std::unordered_map<int, int> distances;
        for (const auto& node : graph.nodes) {
            distances[node.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        std::vector<std::pair<int, int>> priority_queue = {{0, start}};
        while (!priority_queue.empty()) {
            std::sort(priority_queue.begin(), priority_queue.end());
            int current_distance = priority_queue[0].first;
            int current_node = priority_queue[0].second;
            priority_queue.erase(priority_queue.begin());
            if (current_node == end) {
                return distances[end];
            }
            for (const auto& neighbor : graph.get_neighbors(current_node)) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.emplace_back(distance, neighbor.first);
                }
            }
        }
        return -1;
    }
};

class SequenceGenerator {
public:
    Graph graph;
    PathFinder path_finder;

    SequenceGenerator(Graph graph, PathFinder path_finder) : graph(graph), path_finder(path_finder) {}

    int generate_sequence() {
        std::vector<int> nodes;
        for (const auto& node : graph.nodes) {
            nodes.push_back(node.first);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, nodes.size() - 1);
        int start_node = nodes[dis(gen)];
        int end_node = nodes[dis(gen)];
        while (end_node == start_node) {
            end_node = nodes[dis(gen)];
        }
        return path_finder.dijkstra(start_node, end_node);
    }
};

int main() {
    Graph graph;
    for (int i = 0; i < 10; ++i) {
        graph.add_node(i);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    for (int i = 0; i < 10; ++i) {
        for (int j = i + 1; j < 10; ++j) {
            graph.add_edge(i, j, dis(gen));
        }
    }
    PathFinder path_finder(graph);
    SequenceGenerator sequence_generator(graph, path_finder);
    while (true) {
        std::cout << sequence_generator.generate_sequence() << std::endl;
    }
    return 0;
}