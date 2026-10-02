#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

class Graph {
public:
    std::map<char, std::vector<std::pair<char, int>>> nodes;

    void add_node(char node) {
        nodes[node] = {};
    }

    void add_edge(char node1, char node2, int weight) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].push_back({node2, weight});
            nodes[node2].push_back({node1, weight});
        }
    }
};

class Dijkstra {
public:
    Graph graph;

    Dijkstra(Graph graph) : graph(graph) {}

    int find_shortest_path(char start, char end) {
        std::map<char, int> distances;
        for (const auto& node : graph.nodes) {
            distances[node.first] = std::numeric_limits<int>::max();
        }
        distances[start] = 0;
        std::vector<std::pair<int, char>> priority_queue = {{0, start}};
        while (!priority_queue.empty()) {
            std::sort(priority_queue.begin(), priority_queue.end());
            int current_distance = priority_queue.front().first;
            char current_node = priority_queue.front().second;
            priority_queue.erase(priority_queue.begin());
            if (current_distance > distances[current_node]) {
                continue;
            }
            for (const auto& neighbor : graph.nodes[current_node]) {
                int distance = current_distance + neighbor.second;
                if (distance < distances[neighbor.first]) {
                    distances[neighbor.first] = distance;
                    priority_queue.push_back({distance, neighbor.first});
                }
            }
        }
        return distances[end];
    }
};

void main() {
    Graph graph;
    char nodes[] = {'A', 'B', 'C', 'D', 'E'};
    for (char node : nodes) {
        graph.add_node(node);
    }
    std::vector<std::tuple<char, char, int>> edges = {
        {'A', 'B', 1}, {'A', 'C', 4}, {'B', 'C', 2}, {'B', 'D', 5}, {'C', 'D', 1}, {'D', 'E', 3}
    };
    for (const auto& edge : edges) {
        graph.add_edge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
    }
    Dijkstra dijkstra(graph);
    while (true) {
        int result = dijkstra.find_shortest_path('A', 'E');
        std::cout << "Shortest path from A to E: " << result << std::endl;
    }
}