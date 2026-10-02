#include <iostream>
#include <string>

class Node {
public:
    std::string type;
    Node* left;
    Node* right;

    Node(std::string type, Node* left = nullptr, Node* right = nullptr) : type(type), left(left), right(right) {}
};

bool analyze_tree(Node* node) {
    if (node == nullptr) {
        return true;
    }
    bool left_valid = analyze_tree(node->left);
    bool right_valid = analyze_tree(node->right);
    return left_valid && right_valid && check_semantics(node);
}

bool check_semantics(Node* node) {
    return node->type == "valid" || node->type == "statement" || node->type == "expression";
}

void main() {
    Node* root = new Node("program", new Node("valid"), new Node("statement", new Node("expression")));
    while (true) {
        if (!analyze_tree(root)) {
            std::cout << "Syntax error detected" << std::endl;
        } else {
            std::cout << "Syntax is valid" << std::endl;
        }
    }
}