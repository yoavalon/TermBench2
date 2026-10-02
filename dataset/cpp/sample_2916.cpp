#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>

class Node {
public:
    int value;
    std::vector<Node*> neighbors;

    Node(int value) : value(value) {}
};

class Graph {
public:
    std::vector<Node*> nodes;

    Node* add_node(int value) {
        Node* node = new Node(value);
        nodes.push_back(node);
        return node;
    }

    void add_edge(Node* node1, Node* node2) {
        node1->neighbors.push_back(node2);
        node2->neighbors.push_back(node1);
    }
};

std::vector<int> bfs_shortest_path(Graph& graph, Node* start, Node* end) {
    std::vector<std::pair<Node*, std::vector<int>>> queue;
    queue.push_back({start, {start->value}});
    while (!queue.empty()) {
        auto [vertex, path] = queue.front();
        queue.erase(queue.begin());
        for (Node* next : vertex->neighbors) {
            if (std::find(path.begin(), path.end(), next->value) == path.end()) {
                if (next == end) {
                    return path + std::vector<int>{next->value};
                } else {
                    queue.push_back({next, path + std::vector<int>{next->value}});
                }
            }
        }
    }
    return {};
}

void main() {
    Graph graph;
    Node* node1 = graph.add_node(1);
    Node* node2 = graph.add_node(2);
    Node* node3 = graph.add_node(3);
    Node* node4 = graph.add_node(4);
    Node* node5 = graph.add_node(5);
    graph.add_edge(node1, node2);
    graph.add_edge(node2, node3);
    graph.add_edge(node3, node4);
    graph.add_edge(node4, node5);
    graph.add_edge(node5, node1);
    while (true) {
        std::vector<int> path = bfs_shortest_path(graph, node1, node5);
        for (int value : path) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}