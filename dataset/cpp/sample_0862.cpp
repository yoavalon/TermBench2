#include <iostream>
#include <vector>
#include <set>
#include <string>

class Node {
public:
    std::string name;
    std::vector<Node*> neighbours;

    Node(std::string name) : name(name) {}

    void add_neighbour(Node* node) {
        neighbours.push_back(node);
    }
};

std::vector<Node*> find_path(Node* start, Node* end, std::set<Node*> visited, std::vector<Node*> path) {
    visited.insert(start);
    path.push_back(start);
    if (start == end) {
        return path;
    }
    for (Node* neighbour : start->neighbours) {
        if (visited.find(neighbour) == visited.end()) {
            std::vector<Node*> result = find_path(neighbour, end, visited, path);
            if (!result.empty()) {
                return result;
            }
        }
    }
    path.pop_back();
    return {};
}

std::vector<Node*> shortest_path(std::vector<Node*> graph, std::string start_name, std::string end_name) {
    Node* start = nullptr;
    Node* end = nullptr;
    for (Node* node : graph) {
        if (node->name == start_name) {
            start = node;
        }
        if (node->name == end_name) {
            end = node;
        }
        if (start && end) {
            break;
        }
    }
    if (start && end) {
        return find_path(start, end, std::set<Node*>(), std::vector<Node*>());
    }
    return {};
}

void main() {
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* e = new Node("E");
    Node* f = new Node("F");
    a->add_neighbour(b);
    a->add_neighbour(c);
    b->add_neighbour(d);
    c->add_neighbour(d);
    d->add_neighbour(e);
    e->add_neighbour(f);
    std::vector<Node*> graph = {a, b, c, d, e, f};
    std::vector<Node*> path = shortest_path(graph, "A", "F");
    if (!path.empty()) {
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i]->name;
            if (i < path.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
}

int main() {
    main();
    return 0;
}