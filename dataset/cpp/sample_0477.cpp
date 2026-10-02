#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value) : value(value) {}

    void add_child(Node* node) {
        children.push_back(node);
    }
};

std::vector<std::string> lint(Node* node) {
    std::vector<std::string> errors;
    if (node->value == "error") {
        errors.push_back("Error node found");
    }
    for (Node* child : node->children) {
        errors.insert(errors.end(), lint(child).begin(), lint(child).end());
    }
    return errors;
}

void analyze(Node* tree) {
    while (true) {
        std::vector<std::string> issues = lint(tree);
        if (!issues.empty()) {
            std::cout << "Issues found: ";
            for (const std::string& issue : issues) {
                std::cout << issue << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Tree is clean" << std::endl;
        }
    }
}

int main() {
    Node* root = new Node("ok");
    Node* child1 = new Node("error");
    Node* child2 = new Node("ok");
    root->add_child(child1);
    root->add_child(child2);
    analyze(root);
    return 0;
}