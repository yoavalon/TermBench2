#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

void traverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    lint(node);
    for (Node* child : node->children) {
        traverse(child);
    }
}

void lint(Node* node) {
    if (node->value == "error") {
        throw std::runtime_error("Syntax error detected");
    }
}

void main() {
    Node* child1_1 = new Node("child1.1");
    Node* child1_error = new Node("error");
    Node* child1 = new Node("child1", {child1_error, child1_1});
    Node* child2 = new Node("child2");
    Node* tree = new Node("root", {child1, child2});

    try {
        traverse(tree);
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // Clean up memory
    delete child1_1;
    delete child1_error;
    delete child1;
    delete child2;
    delete tree;
}

int main() {
    main();
    return 0;
}