#include <stdio.h>
#include <stdlib.h>

typedef struct LedgerNode {
    int data;
    struct LedgerNode* next;
} LedgerNode;

typedef struct DecentralizedLedger {
    LedgerNode* head;
    LedgerNode* tail;
} DecentralizedLedger;

void LedgerNode_init(LedgerNode* node, int data) {
    node->data = data;
    node->next = NULL;
}

void DecentralizedLedger_init(DecentralizedLedger* ledger) {
    ledger->head = NULL;
    ledger->tail = NULL;
}

void append(DecentralizedLedger* ledger, int data) {
    LedgerNode* new_node = (LedgerNode*)malloc(sizeof(LedgerNode));
    LedgerNode_init(new_node, data);
    if (!ledger->head) {
        ledger->head = new_node;
        ledger->tail = new_node;
    } else {
        ledger->tail->next = new_node;
        ledger->tail = new_node;
    }
}

void consensus(DecentralizedLedger* ledger) {
    LedgerNode* current = ledger->head;
    while (current) {
        if (current->data % 2 == 0) {
            current->data += 1;
        } else {
            current->data -= 1;
        }
        current = current->next;
    }
}

void simulate_ledger() {
    DecentralizedLedger ledger;
    DecentralizedLedger_init(&ledger);
    for (int i = 1; i <= 100; i++) {
        append(&ledger, i);
    }
    while (1) {
        consensus(&ledger);
    }
}

int main() {
    simulate_ledger();
    return 0;
}