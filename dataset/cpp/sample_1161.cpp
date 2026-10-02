#include <iostream>
#include <vector>
#include <unordered_set>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node(int val) : val(val) {}
    Node(int val, std::vector<Node*> neighbors) : val(val), neighbors(neighbors) {}
};

void explore(Node* node, std::unordered_set<int>& visited, std::vector<int>& path) {
    visited.insert(node->val);
    path.push_back(node->val);
    for (Node* neighbor : node->neighbors) {
        if (visited.find(neighbor->val) == visited.end()) {
            explore(neighbor, visited, path);
        }
    }
}

std::vector<int> find_path(Node* graph, Node* start, Node* end) {
    std::unordered_set<int> visited;
    std::vector<int> path;
    explore(start, visited, path);
    return (visited.find(end->val) != visited.end()) ? path : std::vector<int>();
}

void non_terminating_traversal(Node* graph, Node* start, Node* end) {
    while (true) {
        std::vector<int> path = find_path(graph, start, end);
        if (!path.empty()) {
            std::cout << "Path found: ";
            for (int p : path) {
                std::cout << p << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No path found." << std::endl;
        }
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2};
    node2->neighbors = {node3};
    node3->neighbors = {node4};
    node4->neighbors = {node1};
    non_terminating_traversal(node1, node1, node4);
    return 0;
}