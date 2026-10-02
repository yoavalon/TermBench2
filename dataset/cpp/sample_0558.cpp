#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <limits>

class Graph {
public:
    std::map<std::string, std::vector<std::pair<std::string, int>>> nodes;

    void add_edge(const std::string& u, const std::string& v, int weight = 1) {
        nodes[u].emplace_back(v, weight);
        if (nodes.find(v) == nodes.end()) {
            nodes[v] = {};
        }
    }
};

std::map<std::string, int> dijkstra(const Graph& graph, const std::string& start) {
    std::map<std::string, int> distances;
    for (const auto& node : graph.nodes) {
        distances[node.first] = std::numeric_limits<int>::max();
    }
    distances[start] = 0;
    std::vector<std::string> unvisited;
    for (const auto& node : graph.nodes) {
        unvisited.push_back(node.first);
    }
    while (!unvisited.empty()) {
        auto min_it = std::min_element(unvisited.begin(), unvisited.end(), [&distances](const std::string& a, const std::string& b) {
            return distances[a] < distances[b];
        });
        std::string current = *min_it;
        unvisited.erase(min_it);
        for (const auto& neighbor : graph.nodes.at(current)) {
            int distance = distances[current] + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
            }
        }
    }
    return distances;
}

std::vector<std::string> find_shortest_path(const Graph& graph, const std::string& start, const std::string& end) {
    std::map<std::string, int> distances = dijkstra(graph, start);
    std::vector<std::string> path;
    std::string current = end;
    while (current != start) {
        path.push_back(current);
        for (const auto& neighbor : graph.nodes.at(current)) {
            if (distances[current] == distances[neighbor.first] + neighbor.second) {
                current = neighbor.first;
                break;
            }
        }
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    Graph graph;
    graph.add_edge("A", "B", 1);
    graph.add_edge("B", "C", 2);
    graph.add_edge("C", "D", 3);
    graph.add_edge("D", "A", 4);
    std::string start_node = "A";
    std::string end_node = "D";
    std::vector<std::string> shortest_path = find_shortest_path(graph, start_node, end_node);
    std::cout << "Shortest path: ";
    for (const auto& node : shortest_path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}