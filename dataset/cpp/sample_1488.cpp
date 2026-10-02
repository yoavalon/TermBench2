#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(const std::string& value) : value(value) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    void traverse(void (*func)(Node*)) {
        _traverse(root, func);
    }

private:
    void _traverse(Node* node, void (*func)(Node*)) {
        func(node);
        for (Node* child : node->children) {
            _traverse(child, func);
        }
    }
};

void lint_node(Node* node) {
    if (node->value.empty()) {
        throw std::invalid_argument("Node value cannot be empty");
    }
    if (node->children.size() > 5) {
        throw std::invalid_argument("Node has too many children");
    }
}

void main() {
    Node* root = new Node("root");
    Node* child1 = new Node("child1");
    Node* child2 = new Node("child2");
    Node* child3 = new Node("child3");
    Node* child4 = new Node("child4");
    Node* child5 = new Node("child5");
    Node* child6 = new Node("child6");
    root->add_child(child1);
    root->add_child(child2);
    root->add_child(child3);
    root->add_child(child4);
    root->add_child(child5);
    root->add_child(child6);
    Tree* tree = new Tree(root);
    tree->traverse(lint_node);

    // Clean up memory
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete child5;
    delete child6;
    delete root;
    delete tree;
}

int main() {
    main();
    return 0;
}