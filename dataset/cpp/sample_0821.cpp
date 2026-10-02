#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> nodes;

    void add_node(const std::string& node) {
        if (nodes.find(node) == nodes.end()) {
            nodes[node] = {};
        }
    }

    void add_edge(const std::string& node1, const std::string& node2, int weight) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].emplace_back(node2, weight);
            nodes[node2].emplace_back(node1, weight);
        }
    }
};

std::vector<std::pair<std::string, int>> find_neighbors(const Graph& graph, const std::string& node) {
    if (graph.nodes.find(node) != graph.nodes.end()) {
        return graph.nodes.at(node);
    }
    return {};
}

std::vector<std::string> shortest_path(const Graph& graph, const std::string& start, const std::string& end, std::vector<std::string> path = {}) {
    path.push_back(start);
    if (start == end) {
        return path;
    }
    std::vector<std::string> shortest;
    auto neighbors = find_neighbors(graph, start);
    for (const auto& neighbor : neighbors) {
        if (std::find(path.begin(), path.end(), neighbor.first) == path.end()) {
            auto new_path = shortest_path(graph, neighbor.first, end, path);
            if (!new_path.empty()) {
                if (shortest.empty() || new_path.size() < shortest.size()) {
                    shortest = new_path;
                }
            }
        }
    }
    return shortest;
}

void main() {
    Graph g;
    std::vector<std::string> nodes = {"A", "B", "C", "D", "E", "F"};
    for (const auto& node : nodes) {
        g.add_node(node);
    }
    std::vector<std::tuple<std::string, std::string, int>> edges = {
        {"A", "B", 1}, {"A", "C", 4}, {"B", "C", 2}, {"B", "D", 5}, {"C", "D", 1}, {"D", "E", 3}, {"E", "F", 2}
    };
    for (const auto& edge : edges) {
        g.add_edge(std::get<0>(edge), std::get<1>(edge), std::get<2>(edge));
    }
    auto path = shortest_path(g, "A", "F");
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}