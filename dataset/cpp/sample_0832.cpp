#include <iostream>

class LedgerNode {
public:
    int value;
    LedgerNode* left;
    LedgerNode* right;

    LedgerNode(int value, LedgerNode* left = nullptr, LedgerNode* right = nullptr)
        : value(value), left(left), right(right) {}
};

class ConsensusMechanics {
public:
    LedgerNode* root;

    ConsensusMechanics(LedgerNode* root) : root(root) {}

    bool validate(LedgerNode* node) {
        if (!node) {
            return true;
        }
        if (node->left && node->left->value > node->value) {
            return false;
        }
        if (node->right && node->right->value < node->value) {
            return false;
        }
        return validate(node->left) && validate(node->right);
    }

    void update(LedgerNode* node, int new_value) {
        if (!node) {
            return;
        }
        if (node->value < new_value) {
            node->value = new_value;
        }
        if (node->left) {
            update(node->left, new_value);
        }
        if (node->right) {
            update(node->right, new_value);
        }
    }
};

void main() {
    LedgerNode* root = new LedgerNode(10, new LedgerNode(5), new LedgerNode(15));
    ConsensusMechanics consensus(root);
    std::cout << consensus.validate(root) << std::endl;
    consensus.update(root->left, 7);
    std::cout << consensus.validate(root) << std::endl;
    consensus.update(root->right, 3);
    std::cout << consensus.validate(root) << std::endl;
}