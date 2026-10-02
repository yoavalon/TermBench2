#include <iostream>
#include <vector>
#include <unordered_set>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value) : value(value) {}

    void add_child(Node* child_node) {
        children.push_back(child_node);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root_node) : root(root_node) {}

    bool validate(Node* node, std::unordered_set<Node*>& visited) {
        if (visited.find(node) != visited.end()) {
            return false;
        }
        visited.insert(node);
        for (Node* child : node->children) {
            if (!validate(child, visited)) {
                return false;
            }
        }
        return true;
    }
};

class Linter {
public:
    Tree* tree;

    Linter(Tree* tree) : tree(tree) {}

    bool check_syntax() {
        return tree->validate(tree->root, std::unordered_set<Node*>());
    }
};

void main() {
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(new Node(4));
    child2->add_child(new Node(5));
    Tree* tree = new Tree(root);
    Linter* linter = new Linter(tree);
    bool result = linter->check_syntax();
    std::cout << "Syntax Valid: " << (result ? "true" : "false") << std::endl;
}