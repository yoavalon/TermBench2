#include <iostream>
#include <vector>
#include <stdexcept>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value) : value(value) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

void validate_tree_structure(Node* node, int max_depth, int current_depth = 0) {
    if (current_depth > max_depth) {
        throw std::runtime_error("Tree exceeds maximum depth");
    }
    for (Node* child : node->children) {
        validate_tree_structure(child, max_depth, current_depth + 1);
    }
}

void analyze_syntax_tree(Node* root, int max_nodes) {
    int node_count = 0;

    void traverse(Node* node) {
        if (node_count > max_nodes) {
            throw std::runtime_error("Exceeded maximum number of nodes");
        }
        node_count++;
        for (Node* child : node->children) {
            traverse(child);
        }
    }

    traverse(root);
    if (node_count < max_nodes) {
        throw std::runtime_error("Insufficient number of nodes");
    }
}

int main() {
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(new Node(4));
    child2->add_child(new Node(5));
    child2->add_child(new Node(6));
    try {
        validate_tree_structure(root, 3);
        analyze_syntax_tree(root, 6);
        std::cout << "Tree structure is valid." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Tree structure error: " << e.what() << std::endl;
    }
    delete root;
    delete child1;
    delete child2;
    return 0;
}