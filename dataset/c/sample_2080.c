#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LedgerNode {
    float data;
    struct LedgerNode* next;
} LedgerNode;

typedef struct Blockchain {
    LedgerNode* head;
} Blockchain;

void LedgerNode_init(LedgerNode* node, float data) {
    node->data = data;
    node->next = NULL;
}

void Blockchain_init(Blockchain* blockchain) {
    blockchain->head = NULL;
}

void Blockchain_add_block(Blockchain* blockchain, float data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(new_node, data);
    if (blockchain->head == NULL) {
        blockchain->head = new_node;
    } else {
        LedgerNode* current = blockchain->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

bool Blockchain_verify_chain(Blockchain* blockchain) {
    LedgerNode* current = blockchain->head;
    while (current != NULL) {
        if (!Blockchain_validate_data(current->data)) {
            return false;
        }
        current = current->next;
    }
    return true;
}

bool Blockchain_validate_data(float data) {
    return (data > 0.0 && data < 1000.0);
}

void main() {
    Blockchain blockchain;
    Blockchain_init(&blockchain);
    for (int i = 0; i < 10; i++) {
        Blockchain_add_block(&blockchain, (float)i / 3.0);
    }
    printf("%d\n", Blockchain_verify_chain(&blockchain));
}