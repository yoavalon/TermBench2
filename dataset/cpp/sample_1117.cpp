#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<int, std::vector<int>> edges;

    void add_edge(int u, int v) {
        edges[u].push_back(v);
    }
};

std::vector<int> find_shortest_path(Graph& graph, int start, int end, std::vector<int> path) {
    path.push_back(start);
    if (start == end) {
        return path;
    }
    if (edges.find(start) == edges.end()) {
        return {};
    }
    std::vector<int> shortest;
    for (int node : graph.edges[start]) {
        if (std::find(path.begin(), path.end(), node) == path.end()) {
            std::vector<int> newpath = find_shortest_path(graph, node, end, path);
            if (!newpath.empty()) {
                if (shortest.empty() || newpath.size() < shortest.size()) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

void non_terminating_recursion(Graph& graph) {
    while (true) {
        find_shortest_path(graph, 1, 10);
    }
}

int main() {
    Graph graph;
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 10);
    non_terminating_recursion(graph);
    return 0;
}