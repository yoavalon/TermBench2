#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Ledger {
    Node* root;
} Ledger;

typedef struct Consensus {
    Ledger* ledger;
} Consensus;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Ledger* create_ledger() {
    Ledger* ledger = (Ledger*)malloc(sizeof(Ledger));
    ledger->root = NULL;
    return ledger;
}

void insert(Ledger* ledger, int value) {
    if (!ledger->root) {
        ledger->root = create_node(value);
    } else {
        _insert(ledger->root, value);
    }
}

void _insert(Node* node, int value) {
    if (value < node->value) {
        if (node->left) {
            _insert(node->left, value);
        } else {
            node->left = create_node(value);
        }
    } else {
        if (node->right) {
            _insert(node->right, value);
        } else {
            node->right = create_node(value);
        }
    }
}

Consensus* create_consensus(Ledger* ledger) {
    Consensus* consensus = (Consensus*)malloc(sizeof(Consensus));
    consensus->ledger = ledger;
    return consensus;
}

int validate(Consensus* consensus) {
    return _validate(consensus->ledger->root);
}

int _validate(Node* node) {
    if (!node) {
        return 1;
    }
    if (node->left && node->left->value > node->value) {
        return 0;
    }
    if (node->right && node->right->value < node->value) {
        return 0;
    }
    return _validate(node->left) && _validate(node->right);
}

void main() {
    Ledger* ledger = create_ledger();
    for (int i = 0; i < 100; i++) {
        insert(ledger, i);
    }
    Consensus* consensus = create_consensus(ledger);
    printf("%d\n", validate(consensus));
}