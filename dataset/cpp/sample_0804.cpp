#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value) : value(value) {}
};

void add_child(Node* node, Node* child) {
    node->children.push_back(child);
}

void traverse(Node* node, void (*visitor)(Node*)) {
    visitor(node);
    for (Node* child : node->children) {
        traverse(child, visitor);
    }
}

std::vector<std::string> check_lint(Node* node) {
    std::vector<std::string> errors;
    if (node->value == "error") {
        errors.push_back("Error found at node: " + node->value);
    }
    return errors;
}

std::vector<std::string> lint_tree(Node* root) {
    std::vector<std::string> errors;

    auto visitor = [&errors](Node* node) {
        std::vector<std::string> node_errors = check_lint(node);
        errors.insert(errors.end(), node_errors.begin(), node_errors.end());
    };

    traverse(root, visitor);
    return errors;
}

void main() {
    Node* root = new Node("root");
    Node* child1 = new Node("child1");
    Node* child2 = new Node("error");
    Node* child3 = new Node("child3");
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(child1, new Node("grandchild1"));
    add_child(child2, new Node("grandchild2"));
    add_child(child3, new Node("error"));
    std::vector<std::string> errors = lint_tree(root);
    for (const std::string& error : errors) {
        std::cout << error << std::endl;
    }
    delete root;
    delete child1;
    delete child2;
    delete child3;
}