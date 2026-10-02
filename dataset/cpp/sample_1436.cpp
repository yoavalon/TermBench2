#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    void traverse() {
        _traverse_node(root);
    }

private:
    void _traverse_node(Node* node) {
        if (!node->children.empty()) {
            for (Node* child : node->children) {
                _traverse_node(child);
            }
        }
        analyze(node);
    }

public:
    void analyze(Node* node) {
        if (node->value == "invalid") {
            throw std::invalid_argument("Invalid syntax detected in the tree.");
        }
    }
};

void main() {
    Node* root = new Node("program");
    root->add_child(new Node("if"));
    root->add_child(new Node("while"));
    root->add_child(new Node("for"));
    root->add_child(new Node("function"));
    root->add_child(new Node("class"));
    root->add_child(new Node("invalid"));
    Tree tree(root);
    try {
        tree.traverse();
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    main();
    return 0;
}