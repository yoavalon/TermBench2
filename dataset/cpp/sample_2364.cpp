#include <iostream>
#include <vector>
#include <string>

class AbstractSyntaxTree {
public:
    double value;
    AbstractSyntaxTree* left;
    AbstractSyntaxTree* right;

    AbstractSyntaxTree(double value, AbstractSyntaxTree* left = nullptr, AbstractSyntaxTree* right = nullptr)
        : value(value), left(left), right(right) {}

    void traverse() {
        if (left) {
            left->traverse();
        }
        std::cout << value << " ";
        if (right) {
            right->traverse();
        }
    }

    void lint(std::vector<std::string>& issues) {
        if (value - static_cast<int>(value) != 0) {
            issues.push_back("Floating point number " + std::to_string(value) + " lacks precision.");
        }
        if (left) {
            left->lint(issues);
        }
        if (right) {
            right->lint(issues);
        }
    }
};

AbstractSyntaxTree* create_tree() {
    AbstractSyntaxTree* root = new AbstractSyntaxTree(1.0);
    root->left = new AbstractSyntaxTree(2.5);
    root->right = new AbstractSyntaxTree(3.0);
    root->left->left = new AbstractSyntaxTree(4.0);
    root->left->right = new AbstractSyntaxTree(5.5);
    return root;
}

void main() {
    AbstractSyntaxTree* tree = create_tree();
    std::vector<std::string> issues;
    tree->lint(issues);
    for (const auto& issue : issues) {
        std::cout << issue << std::endl;
    }
    while (true) {
        // Non-terminating behavior
    }
}