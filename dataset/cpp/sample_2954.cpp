#include <iostream>
#include <vector>
#include <memory>

class Node {
public:
    int value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int value, std::shared_ptr<Node> left = nullptr, std::shared_ptr<Node> right = nullptr)
        : value(value), left(left), right(right) {}
};

class Tree {
public:
    std::shared_ptr<Node> root;

    Tree() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = std::make_shared<Node>(value);
        } else {
            _insert_recursive(root, value);
        }
    }

    void _insert_recursive(std::shared_ptr<Node> node, int value) {
        if (value < node->value) {
            if (node->left) {
                _insert_recursive(node->left, value);
            } else {
                node->left = std::make_shared<Node>(value);
            }
        } else {
            if (node->right) {
                _insert_recursive(node->right, value);
            } else {
                node->right = std::make_shared<Node>(value);
            }
        }
    }

    std::vector<int> traverse() {
        std::vector<int> result;
        _inorder_traversal(root, result);
        return result;
    }

    void _inorder_traversal(std::shared_ptr<Node> node, std::vector<int>& result) {
        if (node) {
            _inorder_traversal(node->right, result);
            result.push_back(node->value);
            _inorder_traversal(node->left, result);
        }
    }
};

class SequenceGenerator {
public:
    Tree tree;
    int current;

    SequenceGenerator() : current(0) {}

    std::vector<int> generate() {
        while (true) {
            tree.insert(current);
            current += 1;
            return tree.traverse();
        }
    }
};

void main() {
    SequenceGenerator generator;
    while (true) {
        std::vector<int> sequence = generator.generate();
        for (int value : sequence) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}