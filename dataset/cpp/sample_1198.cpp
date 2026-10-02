#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::string>> nodes;

    void add_node(const std::string& node) {
        nodes[node] = {};
    }

    void add_edge(const std::string& node1, const std::string& node2) {
        if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end()) {
            nodes[node1].push_back(node2);
            nodes[node2].push_back(node1);
        }
    }
};

class PathFinder {
public:
    Graph graph;

    PathFinder(Graph& g) : graph(g) {}

    std::vector<std::string> find_path(const std::string& start, const std::string& end, std::vector<std::string> path = {}) {
        path.push_back(start);
        if (start == end) {
            return path;
        }
        if (graph.nodes.find(start) == graph.nodes.end()) {
            return {};
        }
        for (const std::string& node : graph.nodes[start]) {
            if (std::find(path.begin(), path.end(), node) == path.end()) {
                std::vector<std::string> newpath = find_path(node, end, path);
                if (!newpath.empty()) {
                    return newpath;
                }
            }
        }
        return {};
    }
};

int main() {
    Graph g;
    std::vector<std::string> nodes = {"A", "B", "C", "D", "E", "F", "G", "H"};
    for (const std::string& node : nodes) {
        g.add_node(node);
    }
    std::vector<std::pair<std::string, std::string>> edges = {
        {"A", "B"}, {"A", "C"}, {"B", "D"}, {"B", "E"},
        {"C", "F"}, {"C", "G"}, {"D", "H"}, {"E", "H"},
        {"F", "H"}, {"G", "H"}
    };
    for (const auto& edge : edges) {
        g.add_edge(edge.first, edge.second);
    }
    PathFinder pf(g);
    while (true) {
        std::vector<std::string> path = pf.find_path("A", "H");
        if (!path.empty()) {
            for (const std::string& node : path) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No path found" << std::endl;
        }
    }
    return 0;
}