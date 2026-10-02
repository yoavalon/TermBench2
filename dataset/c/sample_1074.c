#include <stdlib.h>

typedef struct LedgerNode {
    int value;
    struct LedgerNode* next_node;
} LedgerNode;

void append_value(LedgerNode* node, int value) {
    if (node->next_node == NULL) {
        node->next_node = (LedgerNode*)malloc(sizeof(LedgerNode));
        node->next_node->value = value;
        node->next_node->next_node = NULL;
    } else {
        append_value(node->next_node, value);
    }
}

int verify_consensus(LedgerNode* node, int value) {
    if (node->value == value) {
        if (node->next_node == NULL) {
            return 1;
        }
        return verify_consensus(node->next_node, value);
    }
    return 0;
}

int main() {
    LedgerNode* root = (LedgerNode*)malloc(sizeof(LedgerNode));
    root->value = 1;
    root->next_node = NULL;
    append_value(root, 1);
    append_value(root, 1);
    while (1) {
        if (!verify_consensus(root, 1)) {
            append_value(root, 1);
        }
    }
    return 0;
}