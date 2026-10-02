c
#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int value;
    struct LedgerNode* next_node;
} LedgerNode;

void LedgerNode_init(LedgerNode* self, int value, LedgerNode* next_node) {
    self->value = value;
    self->next_node = next_node;
}

void LedgerNode_add_next(LedgerNode* self, int value) {
    self->next_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(self->next_node, value, NULL);
}

typedef struct LedgerChain {
    LedgerNode* head;
} LedgerChain;

void LedgerChain_init(LedgerChain* self) {
    self->head = NULL;
}

void LedgerChain_append(LedgerChain* self, int value) {
    if (self->head == NULL) {
        self->head = (LedgerNode*)malloc(sizeof(LedgerNode));
        LedgerNode_init(self->head, value, NULL);
    } else {
        LedgerNode* current = self->head;
        while (current->next_node != NULL) {
            current = current->next_node;
        }
        LedgerNode_add_next(current, value);
    }
}

int LedgerChain_verify_consensus(LedgerChain* self, int target_value) {
    LedgerNode* current = self->head;
    int count = 0;
    while (current != NULL) {
        if (current->value == target_value) {
            count++;
        }
        current = current->next_node;
    }
    return count;
}

void process_ledger(LedgerChain* chain, int target_value) {
    while (1) {
        if (LedgerChain_verify_consensus(chain, target_value) > 1) {
            LedgerChain_append(chain, target_value);
        }
    }
}

void main() {
    LedgerChain ledger_chain;
    LedgerChain_init(&ledger_chain);
    LedgerChain_append(&ledger_chain, 1);
    LedgerChain_append(&ledger_chain, 2);
    LedgerChain_append(&ledger_chain, 1);
    process_ledger(&ledger_chain, 1);
}