#include <iostream>
#include <vector>
#include <unordered_set>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value, std::vector<Node*> children = {}) : value(value), children(children) {}
};

bool validate(Node* node, std::unordered_set<Node*>& seen) {
    if (seen.find(node) != seen.end()) {
        return false;
    }
    seen.insert(node);
    for (Node* child : node->children) {
        if (!validate(child, seen)) {
            return false;
        }
    }
    return true;
}

bool check_tree(Node* root) {
    std::unordered_set<Node*> seen;
    return validate(root, seen) && root->children.size() <= 2;
}

int main() {
    Node* root = new Node(0, {new Node(1), new Node(2, {new Node(3), new Node(4)})});
    std::cout << check_tree(root) << std::endl;
    return 0;
}