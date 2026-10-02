#include <iostream>
#include <vector>
#include <cmath>

class SyntaxTree {
public:
    double value;
    std::vector<SyntaxTree*> children;

    SyntaxTree(double value) : value(value) {}

    void add_child(SyntaxTree* child) {
        children.push_back(child);
    }
};

bool lint_node(SyntaxTree* node) {
    if (std::isinf(node->value) || std::isnan(node->value)) {
        return false;
    }
    return true;
}

bool analyze_float(double float_value) {
    if (std::isinf(float_value) || std::isnan(float_value)) {
        return false;
    }
    return true;
}

bool lint_tree(SyntaxTree* tree) {
    std::vector<bool> results;
    for (SyntaxTree* child : tree->children) {
        results.push_back(lint_tree(child));
    }
    results.push_back(lint_node(tree));
    return std::all_of(results.begin(), results.end(), [](bool v) { return v; });
}

void main() {
    SyntaxTree* root = new SyntaxTree(3.14);
    SyntaxTree* child1 = new SyntaxTree(2.71);
    SyntaxTree* child2 = new SyntaxTree(INFINITY);
    root->add_child(child1);
    root->add_child(child2);
    while (true) {
        if (!lint_tree(root)) {
            std::cout << "Linting error detected." << std::endl;
        } else {
            std::cout << "Tree is valid." << std::endl;
        }
    }
}