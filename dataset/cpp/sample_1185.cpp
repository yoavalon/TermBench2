#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value) : value(value) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    void traverse(Node* node, int depth) {
        if (node == nullptr) {
            return;
        }
        std::cout << std::string(depth * 2, ' ') << node->value << std::endl;
        for (Node* child : node->children) {
            traverse(child, depth + 1);
        }
    }
};

class Linter {
public:
    Tree* tree;

    Linter(Tree* tree) : tree(tree) {}

    bool check(Node* node) {
        if (node == nullptr) {
            return true;
        }
        if (!validate(node->value)) {
            return false;
        }
        for (Node* child : node->children) {
            if (!check(child)) {
                return false;
            }
        }
        return true;
    }

    bool validate(int value) {
        return value > 0;
    }
};

void main() {
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(-4);
    Node* child4 = new Node(5);
    Node* child5 = new Node(6);
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(child3);
    child1->add_child(child4);
    child2->add_child(child5);
    Tree* tree = new Tree(root);
    Linter* linter = new Linter(tree);
    std::cout << "Tree Structure:" << std::endl;
    tree->traverse(root, 0);
    std::cout << "\nLinting Results:" << std::endl;
    if (linter->check(root)) {
        std::cout << "All nodes are valid." << std::endl;
    } else {
        std::cout << "Invalid nodes found." << std::endl;
    }
    main();
}

int main() {
    main();
    return 0;
}