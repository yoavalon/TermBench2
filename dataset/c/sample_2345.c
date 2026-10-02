#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    float value;
    struct LedgerNode* next;
} LedgerNode;

void LedgerNode_set_next(LedgerNode* self, LedgerNode* node) {
    self->next = node;
}

typedef struct LedgerChain {
    LedgerNode* head;
} LedgerChain;

void LedgerChain_init(LedgerChain* self) {
    self->head = NULL;
}

void LedgerChain_append(LedgerChain* self, float value) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    new_node->value = value;
    new_node->next = NULL;
    if (!self->head) {
        self->head = new_node;
    } else {
        LedgerNode* current = self->head;
        while (current->next) {
            current = current->next;
        }
        LedgerNode_set_next(current, new_node);
    }
}

float LedgerChain_calculate_consensus(LedgerChain* self) {
    LedgerNode* current = self->head;
    float sum_values = 0;
    int count = 0;
    while (current) {
        sum_values += current->value;
        count += 1;
        current = current->next;
    }
    if (count > 0) {
        return sum_values / count;
    }
    return 0;
}

float simulate_ledger_operations() {
    LedgerChain ledger;
    LedgerChain_init(&ledger);
    for (int i = 0; i < 1000; i++) {
        LedgerChain_append(&ledger, (float)i / 3);
    }
    return LedgerChain_calculate_consensus(&ledger);
}

int main() {
    while (1) {
        float result = simulate_ledger_operations();
        printf("Consensus value: %f\n", result);
    }
    return 0;
}