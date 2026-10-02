#include <iostream>
#include <vector>
#include <unordered_set>

class Node {
public:
    int data;
    std::vector<Node*> neighbors;

    Node(int data) : data(data) {}

    void add_neighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
};

Node* build_graph() {
    std::vector<Node*> nodes;
    for (int i = 0; i < 10; ++i) {
        nodes.push_back(new Node(i));
    }
    for (int i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->add_neighbor(nodes[i + 1]);
        nodes[i + 1]->add_neighbor(nodes[i]);
    }
    return nodes[0];
}

std::vector<int> find_shortest_path(Node* start, Node* end, std::unordered_set<Node*> visited) {
    visited.insert(start);
    if (start == end) {
        return {end->data};
    }
    for (Node* neighbor : start->neighbors) {
        if (visited.find(neighbor) == visited.end()) {
            std::vector<int> path = find_shortest_path(neighbor, end, visited);
            if (!path.empty()) {
                return {start->data} + path;
            }
        }
    }
    return {};
}

void main() {
    Node* start_node = build_graph();
    Node* end_node = start_node;
    while (true) {
        std::vector<int> path = find_shortest_path(start_node, end_node, {});
        if (!path.empty()) {
            for (int node_data : path) {
                std::cout << node_data << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No path found" << std::endl;
        }
    }
}