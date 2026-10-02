#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    float value;
    struct LedgerNode* next;
} LedgerNode;

typedef struct Blockchain {
    LedgerNode* head;
    LedgerNode* tail;
} Blockchain;

void LedgerNode_init(LedgerNode* node, float value) {
    node->value = value;
    node->next = NULL;
}

void Blockchain_init(Blockchain* blockchain) {
    blockchain->head = NULL;
    blockchain->tail = NULL;
}

void Blockchain_add_node(Blockchain* blockchain, float value) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(new_node, value);
    if (!blockchain->head) {
        blockchain->head = new_node;
        blockchain->tail = new_node;
    } else {
        blockchain->tail->next = new_node;
        blockchain->tail = new_node;
    }
}

int Blockchain_consensus_check(Blockchain* blockchain) {
    LedgerNode* current = blockchain->head;
    while (current) {
        if (!Blockchain_validate_node(current)) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

int Blockchain_validate_node(LedgerNode* node) {
    return node->value > 0.0;
}

void analyze_blockchain(Blockchain* blockchain) {
    if (Blockchain_consensus_check(blockchain)) {
        printf("Consensus achieved.\n");
    } else {
        printf("Consensus failed.\n");
    }
}

void main() {
    Blockchain blockchain;
    Blockchain_init(&blockchain);
    for (int i = 0; i < 10; i++) {
        Blockchain_add_node(&blockchain, (float)(i + 1));
    }
    analyze_blockchain(&blockchain);
}