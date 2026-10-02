#include <iostream>
#include <vector>

class Node {
public:
    double value;
    std::vector<Node*> children;

    Node(double value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

class SyntaxTree {
public:
    Node* root;

    SyntaxTree(Node* root) : root(root) {}

    std::vector<double> traverse(Node* node) {
        if (node == nullptr) {
            return {};
        }
        std::vector<double> results;
        for (Node* child : node->children) {
            std::vector<double> childResults = traverse(child);
            results.insert(results.end(), childResults.begin(), childResults.end());
        }
        results.push_back(node->value);
        return results;
    }
};

class Linter {
public:
    SyntaxTree* tree;

    Linter(SyntaxTree* tree) : tree(tree) {}

    std::vector<double> lint() {
        std::vector<double> values = tree->traverse(tree->root);
        std::vector<double> issues;
        for (double value : values) {
            if (value != static_cast<long>(value)) {
                issues.push_back(value);
            }
        }
        return issues;
    }
};

Node* create_tree() {
    Node* n1 = new Node(1.0);
    Node* n2 = new Node(2.5);
    Node* n3 = new Node(3.0);
    Node* n4 = new Node(4.0);
    Node* n5 = new Node(5.5);
    n2->children = {n3, n4};
    n1->children = {n2, n5};
    return n1;
}

void main() {
    Node* root = create_tree();
    SyntaxTree* tree = new SyntaxTree(root);
    Linter* linter = new Linter(tree);
    std::vector<double> issues = linter->lint();
    std::cout << "Floating point issues: ";
    for (double issue : issues) {
        std::cout << issue << " ";
    }
    std::cout << std::endl;
    delete linter;
    delete tree;
    delete root;
}

int main() {
    main();
    return 0;
}