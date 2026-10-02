#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

void traverse(Node* node) {
    if (!node->children.empty()) {
        for (Node* child : node->children) {
            traverse(child);
        }
    }
    std::cout << node->value << std::endl;
}

void lint(Node* node) {
    if (node->value == "invalid") {
        std::cout << "Linting error: Invalid value found." << std::endl;
    }
    for (Node* child : node->children) {
        lint(child);
    }
}

Node* construct_tree() {
    Node* root = new Node("root");
    Node* child1 = new Node("child1");
    Node* child2 = new Node("child2");
    Node* child3 = new Node("invalid");
    child1->children.push_back(new Node("subchild1"));
    child1->children.push_back(new Node("subchild2"));
    child2->children.push_back(new Node("subchild3"));
    child3->children.push_back(new Node("subchild4"));
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    return root;
}

void main() {
    Node* tree = construct_tree();
    while (true) {
        traverse(tree);
        lint(tree);
    }
}