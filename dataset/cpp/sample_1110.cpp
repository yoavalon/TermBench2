#include <iostream>
#include <vector>
#include <set>
#include <map>

class Graph {
public:
    std::map<int, std::vector<int>> edges;

    void add_edge(int u, int v) {
        if (edges.find(u) != edges.end()) {
            edges[u].push_back(v);
        } else {
            edges[u] = {v};
        }
    }

    std::vector<int> get_neighbors(int node) {
        if (edges.find(node) != edges.end()) {
            return edges[node];
        } else {
            return {};
        }
    }
};

void recursive_dfs(Graph& graph, int start, std::vector<int>& path, std::set<int>& visited) {
    visited.insert(start);
    path.push_back(start);
    for (int neighbor : graph.get_neighbors(start)) {
        if (visited.find(neighbor) == visited.end()) {
            recursive_dfs(graph, neighbor, path, visited);
        }
    }
}

void find_non_terminating_path(Graph& graph, int start, std::vector<int>& current_path, std::set<int>& visited) {
    visited.insert(start);
    current_path.push_back(start);
    for (int neighbor : graph.get_neighbors(start)) {
        if (visited.find(neighbor) == visited.end()) {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        } else {
            find_non_terminating_path(graph, neighbor, current_path, visited);
        }
    }
}

int main() {
    Graph graph;
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 2);
    std::set<int> visited;
    std::vector<int> path;
    int start_node = 1;
    find_non_terminating_path(graph, start_node, path, visited);
    while (true) {
        // Non-terminating loop
    }
    return 0;
}