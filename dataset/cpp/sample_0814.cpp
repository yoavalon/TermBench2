#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class Ledger {
public:
    Node* root;

    Ledger() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = new Node(value);
        } else {
            _insert(root, value);
        }
    }

    void _insert(Node* node, int value) {
        if (value < node->value) {
            if (node->left) {
                _insert(node->left, value);
            } else {
                node->left = new Node(value);
            }
        } else {
            if (node->right) {
                _insert(node->right, value);
            } else {
                node->right = new Node(value);
            }
        }
    }
};

class Consensus {
public:
    Ledger* ledger;

    Consensus(Ledger* ledger) : ledger(ledger) {}

    bool validate() {
        return _validate(ledger->root);
    }

    bool _validate(Node* node) {
        if (!node) {
            return true;
        }
        if (node->left && node->left->value > node->value) {
            return false;
        }
        if (node->right && node->right->value < node->value) {
            return false;
        }
        return _validate(node->left) && _validate(node->right);
    }
};

void main() {
    Ledger ledger;
    for (int i = 0; i < 100; ++i) {
        ledger.insert(i);
    }
    Consensus consensus(&ledger);
    std::cout << consensus.validate() << std::endl;
}

int main() {
    main();
    return 0;
}