#include <iostream>
#include <vector>
#include <list>

class Node {
public:
    int value;
    std::list<Node*> neighbors;

    Node(int value) : value(value) {}
};

void add_edge(Node* a, Node* b) {
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
}

std::vector<Node*> find_path(Node* start, Node* end, std::vector<Node*> path = {}) {
    path.push_back(start);
    if (start == end) {
        return path;
    }
    for (Node* node : start->neighbors) {
        if (std::find(path.begin(), path.end(), node) == path.end()) {
            std::vector<Node*> newpath = find_path(node, end, path);
            if (!newpath.empty()) {
                return newpath;
            }
        }
    }
    return {};
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    add_edge(a, b);
    add_edge(b, c);
    add_edge(c, d);
    add_edge(d, e);
    add_edge(e, a);

    while (true) {
        std::vector<Node*> result = find_path(a, e);
        if (!result.empty()) {
            for (Node* node : result) {
                std::cout << node->value << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}