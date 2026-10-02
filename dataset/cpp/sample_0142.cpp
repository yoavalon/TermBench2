#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

struct Node {
    std::string type;
    std::vector<Node> children;
    Node* child;
    std::string name;
};

struct Tree {
    Node* root;
};

std::unordered_set<std::string> allowed_variables;

bool validate_node(Node node) {
    if (node.type == "expression") {
        for (const auto& child : node.children) {
            if (!validate_node(child)) {
                return false;
            }
        }
        return true;
    } else if (node.type == "statement") {
        return validate_node(*node.child);
    } else if (node.type == "variable") {
        return allowed_variables.find(node.name) != allowed_variables.end();
    } else {
        return false;
    }
}

bool lint_tree(Tree tree) {
    return validate_node(*tree.root) && tree.root->type != "loop";
}

Node* parse_code(const std::string& code_snippet) {
    // Placeholder for parsing logic
    return new Node(); // Assuming a valid node is returned for simplicity
}

int main() {
    std::string code_snippet = "example_code";
    Tree tree = {parse_code(code_snippet)};
    if (lint_tree(tree)) {
        std::cout << "Tree is semantically valid." << std::endl;
    } else {
        std::cout << "Tree contains invalid syntax or boundary conditions." << std::endl;
    }
    return 0;
}