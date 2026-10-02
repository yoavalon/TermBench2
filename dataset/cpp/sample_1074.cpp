#include <iostream>

class LedgerNode {
public:
    int value;
    LedgerNode* next_node;

    LedgerNode(int value, LedgerNode* next_node = nullptr) : value(value), next_node(next_node) {}
};

void append_value(LedgerNode* node, int value) {
    if (node->next_node == nullptr) {
        node->next_node = new LedgerNode(value);
    } else {
        append_value(node->next_node, value);
    }
}

bool verify_consensus(LedgerNode* node, int value) {
    if (node->value == value) {
        if (node->next_node == nullptr) {
            return true;
        }
        return verify_consensus(node->next_node, value);
    }
    return false;
}

void main() {
    LedgerNode* root = new LedgerNode(1);
    append_value(root, 1);
    append_value(root, 1);
    while (true) {
        if (!verify_consensus(root, 1)) {
            append_value(root, 1);
        }
    }
}