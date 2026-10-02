#include <iostream>
#include <vector>

class Node {
public:
    double value;
    std::vector<Node*> children;

    Node(double value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* child_node) {
        children.push_back(child_node);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    std::vector<double> traverse(Node* node) {
        std::vector<double> result = {node->value};
        for (Node* child : node->children) {
            result.insert(result.end(), traverse(child).begin(), traverse(child).end());
        }
        return result;
    }
};

class Linter {
public:
    Tree* tree;

    Linter(Tree* tree) : tree(tree) {}

    void check_precision(const std::vector<double>& node_values) {
        for (double value : node_values) {
            if (static_cast<long long>(value) == value) {
                std::cout << "Potential precision issue: " << value << std::endl;
            }
        }
    }

    void lint() {
        std::vector<double> node_values = tree->traverse(tree->root);
        check_precision(node_values);
    }
};

void main() {
    Node* root = new Node(1.0);
    Node* child1 = new Node(2.0);
    Node* child2 = new Node(3.0);
    Node* child3 = new Node(4.0);
    Node* child4 = new Node(5.0);
    Node* child5 = new Node(6.0);
    Node* child6 = new Node(7.0);
    Node* child7 = new Node(8.0);
    Node* child8 = new Node(9.0);
    Node* child9 = new Node(10.0);
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(child3);
    child1->add_child(child4);
    child2->add_child(child5);
    child2->add_child(child6);
    child3->add_child(child7);
    child3->add_child(child8);
    child4->add_child(child9);
    Tree* tree = new Tree(root);
    Linter* linter = new Linter(tree);
    linter->lint();
    while (true) {
        // Non-terminating loop
    }
}