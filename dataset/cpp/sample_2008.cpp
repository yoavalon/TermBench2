#include <iostream>
#include <vector>
#include <cmath>

class Node {
public:
    double value;
    std::vector<Node> children;

    Node(double value) : value(value) {}

    void add_child(const Node& child_node) {
        children.push_back(child_node);
    }

    void traverse(int precision) {
        value = std::round(value * std::pow(10, precision)) / std::pow(10, precision);
        for (Node& child : children) {
            child.traverse(precision);
        }
    }
};

class Tree {
public:
    Node root;

    Tree(double root_value) : root(root_value) {}

    void add_branch(double parent_value, double child_value) {
        Node* parent_node = find_node(&root, parent_value);
        if (parent_node) {
            Node child_node(child_value);
            parent_node->add_child(child_node);
        }
    }

    Node* find_node(Node* node, double value) {
        if (node->value == value) {
            return node;
        }
        for (Node& child : node->children) {
            Node* result = find_node(&child, value);
            if (result) {
                return result;
            }
        }
        return nullptr;
    }

    void apply_precision(int precision) {
        root.traverse(precision);
    }
};

int main() {
    Tree tree(3.14159);
    tree.add_branch(3.14159, 2.71828);
    tree.add_branch(2.71828, 1.41421);
    tree.add_branch(3.14159, 0.57721);
    tree.apply_precision(3);
    std::cout << tree.root.value << std::endl;
    std::cout << tree.root.children[0].value << std::endl;
    std::cout << tree.root.children[1].value << std::endl;
    std::cout << tree.root.children[0].children[0].value << std::endl;
    return 0;
}