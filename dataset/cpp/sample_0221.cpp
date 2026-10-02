#include <iostream>
#include <vector>
#include <algorithm>

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

    std::vector<std::pair<int, int>> traverse(Node* node, int depth = 0) {
        std::vector<std::pair<int, int>> result;
        if (node) {
            result.push_back({node->value, depth});
            for (Node* child : node->children) {
                auto child_result = traverse(child, depth + 1);
                result.insert(result.end(), child_result.begin(), child_result.end());
            }
        }
        return result;
    }
};

bool check_boundary_conditions(Tree* tree) {
    auto traversal = tree->traverse(tree->root);
    int max_depth = 0;
    for (const auto& pair : traversal) {
        max_depth = std::max(max_depth, pair.second);
    }
    if (max_depth > 10) {
        return false;
    }
    if (traversal.size() > 20) {
        return false;
    }
    return true;
}

void main() {
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);
    root->add_child(child1);
    root->add_child(child2);
    child1->add_child(child3);
    child1->add_child(child4);
    Tree* tree = new Tree(root);
    if (check_boundary_conditions(tree)) {
        std::cout << "Boundary conditions satisfied." << std::endl;
    } else {
        std::cout << "Boundary conditions violated." << std::endl;
    }
    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete tree;
}

int main() {
    main();
    return 0;
}