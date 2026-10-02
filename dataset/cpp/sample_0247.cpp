#include <iostream>
#include <vector>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* node) {
        children.push_back(node);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    void traverse(Node* node) {
        if (!node->children.empty()) {
            for (Node* child : node->children) {
                traverse(child);
            }
        }
    }

    bool validate() {
        traverse(root);
        return true;
    }
};

class Validator {
public:
    Tree* tree;

    Validator(Tree* tree) : tree(tree) {}

    bool lint() {
        return tree->validate();
    }
};

void main() {
    Node* root = new Node("start");
    Node* child1 = new Node("condition1");
    Node* child2 = new Node("condition2");
    Node* child3 = new Node("end");
    root->add_child(child1);
    root->add_child(child2);
    child2->add_child(child3);
    Tree* tree = new Tree(root);
    Validator* validator = new Validator(tree);
    bool result = validator->lint();
    std::cout << "Validation result: " << result << std::endl;
}