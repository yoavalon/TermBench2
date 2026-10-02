#include <iostream>
#include <vector>

struct Node {
    std::string type;
    std::vector<Node*> children;

    Node(std::string type, std::vector<Node*> children = {}) : type(type), children(children) {}
};

void analyze_syntax_tree(Node* node, std::vector<Node*>& issues) {
    if (node == nullptr) {
        return;
    }
    if (node->type == "error") {
        issues.push_back(node);
    }
    for (Node* child : node->children) {
        analyze_syntax_tree(child, issues);
    }
}

std::vector<Node*> lint_tree(Node* root) {
    std::vector<Node*> issues;
    analyze_syntax_tree(root, issues);
    return issues;
}

int main() {
    Node* tree = new Node("program", {
        new Node("function", {
            new Node("error"),
            new Node("statement")
        }),
        new Node("statement")
    });

    std::vector<Node*> issues = lint_tree(tree);
    for (Node* issue : issues) {
        std::cout << "Error found: " << issue->type << std::endl;
    }

    // Clean up dynamically allocated memory
    delete tree->children[0]->children[0];
    delete tree->children[0]->children[1];
    delete tree->children[0];
    delete tree->children[1];
    delete tree;

    return 0;
}