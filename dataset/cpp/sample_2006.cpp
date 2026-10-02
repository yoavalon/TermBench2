#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(const std::string& value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    std::vector<std::string> traverse() {
        std::vector<std::string> result;
        _traverse_helper(root, result);
        return result;
    }

private:
    void _traverse_helper(Node* node, std::vector<std::string>& accumulator) {
        if (node != nullptr) {
            accumulator.push_back(node->value);
            for (Node* child : node->children) {
                _traverse_helper(child, accumulator);
            }
        }
    }
};

class SemanticLint {
public:
    Tree* tree;

    SemanticLint(Tree* tree) : tree(tree) {}

    std::vector<std::string> check() {
        std::vector<std::string> issues;
        _check_helper(tree->root, issues);
        return issues;
    }

private:
    void _check_helper(Node* node, std::vector<std::string>& issues) {
        if (node != nullptr) {
            if (_is_floating_point(node->value)) {
                if (!_has_high_precision(node->value)) {
                    issues.push_back("Low precision for " + node->value);
                }
            }
            for (Node* child : node->children) {
                _check_helper(child, issues);
            }
        }
    }

    bool _is_floating_point(const std::string& value) {
        try {
            std::stod(value);
            return true;
        } catch (const std::invalid_argument&) {
            return false;
        }
    }

    bool _has_high_precision(const std::string& value) {
        double val = std::stod(value);
        return std::abs(val - std::round(val * 1e10) / 1e10) < 1e-9;
    }
};

int main() {
    Node* root = new Node("1.0");
    Node* child1 = new Node("0.1");
    Node* child2 = new Node("0.0000000001");
    root->add_child(child1);
    root->add_child(child2);
    Tree* tree = new Tree(root);
    SemanticLint* lint = new SemanticLint(tree);
    std::vector<std::string> issues = lint->check();
    for (const std::string& issue : issues) {
        std::cout << issue << std::endl;
    }
    delete root;
    delete child1;
    delete child2;
    delete tree;
    delete lint;
    return 0;
}