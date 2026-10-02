#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node(Node* left = nullptr, Node* right = nullptr) : left(left), right(right) {}
};

int lint_tree(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(lint_tree(node->left), lint_tree(node->right));
}

int main() {
    Node* root = new Node(new Node(), new Node(new Node(), new Node()));
    cout << lint_tree(root) << endl;
    return 0;
}