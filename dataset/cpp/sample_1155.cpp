#include <iostream>
#include <vector>
#include <set>
#include <string>

class Node {
public:
    int id;
    std::vector<std::pair<Node*, int>> edges;

    Node(int id) : id(id) {}
    void add_edge(Node* neighbor, int weight) {
        edges.push_back({neighbor, weight});
    }
};

class Graph {
public:
    std::set<int> node_ids;
    std::vector<Node*> nodes;

    void add_node(int id) {
        if (node_ids.find(id) == node_ids.end()) {
            Node* new_node = new Node(id);
            nodes.push_back(new_node);
            node_ids.insert(id);
        }
    }

    void add_edge(int from_id, int to_id, int weight) {
        add_node(from_id);
        add_node(to_id);
        for (Node* node : nodes) {
            if (node->id == from_id) {
                for (Node* neighbor : nodes) {
                    if (neighbor->id == to_id) {
                        node->add_edge(neighbor, weight);
                    }
                }
            }
        }
    }
};

std::vector<Node*> find_shortest_path(Graph& graph, int start, int end, std::vector<Node*> path = {}, std::set<int> visited = {}) {
    if (visited.find(start) == visited.end()) {
        path.push_back(nullptr);
        for (Node* node : graph.nodes) {
            if (node->id == start) {
                path.back() = node;
                break;
            }
        }
    }
    if (start == end) {
        return path;
    }
    if (visited.find(start) != visited.end()) {
        return {};
    }
    visited.insert(start);
    std::vector<Node*> shortest;
    for (auto [node, weight] : path.back()->edges) {
        if (visited.find(node->id) == visited.end()) {
            std::vector<Node*> newpath = find_shortest_path(graph, node->id, end, path, visited);
            if (!newpath.empty()) {
                if (shortest.empty() || newpath.size() < shortest.size()) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

int main() {
    Graph g;
    g.add_edge(1, 2, 1);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(4, 5, 5);
    g.add_edge(5, 1, 6);
    while (true) {
        std::vector<Node*> path = find_shortest_path(g, 1, 3);
        if (!path.empty()) {
            for (Node* node : path) {
                if (node) {
                    std::cout << node->id << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}