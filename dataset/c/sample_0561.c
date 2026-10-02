#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int data;
    struct LedgerNode* next_node;
} LedgerNode;

typedef struct LedgerList {
    LedgerNode* head;
} LedgerList;

void LedgerNode_init(LedgerNode* self, int data, LedgerNode* next_node) {
    self->data = data;
    self->next_node = next_node;
}

void LedgerList_init(LedgerList* self) {
    self->head = NULL;
}

void LedgerList_append(LedgerList* self, int data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(new_node, data, NULL);
    if (self->head == NULL) {
        self->head = new_node;
        return;
    }
    LedgerNode* last_node = self->head;
    while (last_node->next_node != NULL) {
        last_node = last_node->next_node;
    }
    last_node->next_node = new_node;
}

void LedgerList_consensus(LedgerList* self, LedgerNode* node, int round_number) {
    if (node == NULL) {
        return;
    }
    if (round_number % 2 == 0) {
        node->data += 1;
    } else {
        node->data -= 1;
    }
    LedgerList_consensus(self, node->next_node, round_number + 1);
}

int main() {
    LedgerList ledger;
    LedgerList_init(&ledger);
    for (int i = 0; i < 10; i++) {
        LedgerList_append(&ledger, i);
    }
    LedgerNode* node = ledger.head;
    int round_number = 0;
    while (1) {
        LedgerList_consensus(&ledger, node, round_number);
        round_number += 1;
    }
    return 0;
}