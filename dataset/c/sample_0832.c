#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int value;
    struct LedgerNode* left;
    struct LedgerNode* right;
} LedgerNode;

typedef struct ConsensusMechanics {
    LedgerNode* root;
} ConsensusMechanics;

LedgerNode* createLedgerNode(int value, LedgerNode* left, LedgerNode* right) {
    LedgerNode* node = (LedgerNode*)malloc(sizeof(LedgerNode));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

ConsensusMechanics* createConsensusMechanics(LedgerNode* root) {
    ConsensusMechanics* mechanics = (ConsensusMechanics*)malloc(sizeof(ConsensusMechanics));
    mechanics->root = root;
    return mechanics;
}

int validate(ConsensusMechanics* mechanics, LedgerNode* node) {
    if (!node) {
        return 1;
    }
    if (node->left && node->left->value > node->value) {
        return 0;
    }
    if (node->right && node->right->value < node->value) {
        return 0;
    }
    return validate(mechanics, node->left) && validate(mechanics, node->right);
}

void update(ConsensusMechanics* mechanics, LedgerNode* node, int new_value) {
    if (!node) {
        return;
    }
    if (node->value < new_value) {
        node->value = new_value;
    }
    if (node->left) {
        update(mechanics, node->left, new_value);
    }
    if (node->right) {
        update(mechanics, node->right, new_value);
    }
}

void main() {
    LedgerNode* root = createLedgerNode(10, createLedgerNode(5, NULL, NULL), createLedgerNode(15, NULL, NULL));
    ConsensusMechanics* consensus = createConsensusMechanics(root);
    printf("%d\n", validate(consensus, root));
    update(consensus, root->left, 7);
    printf("%d\n", validate(consensus, root));
    update(consensus, root->right, 3);
    printf("%d\n", validate(consensus, root));
}