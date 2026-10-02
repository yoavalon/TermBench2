#include <iostream>
#include <vector>

class Node {
public:
    std::string value;
    std::vector<Node*> children;

    Node(std::string value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

void traverse(Node* node, int depth) {
    if (depth == 0) {
        return;
    }
    for (Node* child : node->children) {
        traverse(child, depth - 1);
    }
}

void analyze_syntax_tree(Node* root, int max_depth) {
    traverse(root, max_depth);
}

int main() {
    Node* root = new Node("root", {new Node("child1"), new Node("child2", {new Node("grandchild1")})});
    analyze_syntax_tree(root, 2);

    // Clean up dynamically allocated memory
    delete root->children[1]->children[0];
    delete root->children[1];
    delete root->children[0];
    delete root;

    return 0;
}