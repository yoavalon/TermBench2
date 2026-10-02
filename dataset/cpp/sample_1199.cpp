#include <iostream>
#include <vector>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value) : value(value) {}

    void add_child(Node* child_node) {
        children.push_back(child_node);
    }
};

class Network {
public:
    Node* root;

    Network() : root(nullptr) {}

    void build(int depth, int current_depth = 0, Node* parent = nullptr) {
        if (current_depth < depth) {
            Node* new_node = new Node(current_depth);
            if (parent) {
                parent->add_child(new_node);
            } else {
                root = new_node;
            }
            for (int i = 0; i < 2; ++i) {
                build(depth, current_depth + 1, new_node);
            }
        }
    }

    void traverse(Node* node) {
        if (node) {
            std::cout << node->value << std::endl;
            for (Node* child : node->children) {
                traverse(child);
            }
        }
    }
};

class Optimizer {
public:
    Network* network;

    Optimizer(Network* network) : network(network) {}

    void optimize() {
        network->traverse(network->root);
        optimize();
    }
};

int main() {
    Network network;
    network.build(5);
    Optimizer optimizer(&network);
    optimizer.optimize();
    return 0;
}