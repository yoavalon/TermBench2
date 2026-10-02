#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value) : value(value) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

std::vector<std::string> lint_tree(Node* node) {
    std::vector<std::string> errors;
    if (node->value == "invalid") {
        errors.push_back("Invalid node value: " + node->value);
    }
    for (Node* child : node->children) {
        std::vector<std::string> child_errors = lint_tree(child);
        errors.insert(errors.end(), child_errors.begin(), child_errors.end());
    }
    return errors;
}

void analyze_ast(Node* root) {
    std::vector<std::string> errors = lint_tree(root);
    if (!errors.empty()) {
        std::cout << "Syntax errors found:" << std::endl;
        for (const std::string& error : errors) {
            std::cout << error << std::endl;
        }
    } else {
        std::cout << "No syntax errors detected." << std::endl;
    }
}

int main() {
    Node* root = new Node("valid");
    Node* child1 = new Node("valid");
    Node* child2 = new Node("invalid");
    Node* child3 = new Node("valid");
    child1->add_child(child3);
    root->add_child(child1);
    root->add_child(child2);
    analyze_ast(root);
    return 0;
}