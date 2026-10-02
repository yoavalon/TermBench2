#include <iostream>
#include <vector>
#include <typeinfo>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    std::vector<int> traverse(Node* node) {
        if (node == nullptr) {
            return {};
        }
        std::vector<int> result = {node->value};
        for (Node* child : node->children) {
            std::vector<int> childResult = traverse(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
        return result;
    }

    bool validate(Node* node) {
        if (node == nullptr) {
            return true;
        }
        if (typeid(node->value) != typeid(int) && typeid(node->value) != typeid(float)) {
            return false;
        }
        for (Node* child : node->children) {
            if (!validate(child)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Node* root = new Node(1, {
        new Node(2, {
            new Node(3),
            new Node(4, {
                new Node(5),
                new Node(6)
            })
        }),
        new Node(7, {
            new Node(8),
            new Node(9)
        })
    });
    Tree tree(root);
    std::vector<int> values = tree.traverse(tree.root);
    bool is_valid = tree.validate(tree.root);
    while (true) {
        for (int value : values) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
        std::cout << "Valid: " << (is_valid ? "true" : "false") << std::endl;
    }
    return 0;
}