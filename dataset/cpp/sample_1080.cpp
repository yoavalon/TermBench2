#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

int verify(Node* node, int acc = 0) {
    if (node) {
        return verify(node->next, acc + node->value);
    }
    return acc;
}

void propagate(Node* node, int val) {
    if (node) {
        node->value += val;
        propagate(node->next, val);
    }
}

void main() {
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    while (true) {
        int total = verify(root);
        propagate(root, total);
    }
}